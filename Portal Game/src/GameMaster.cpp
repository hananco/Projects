#include "GameMaster.h"

//==============================CONSTRUCTOR====================================
GameMaster::GameMaster() : m_dataBar(),
m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Portal", sf::Style::Resize)
{
	m_window.setFramerateLimit(LIMIT);
	m_menu.runMenu(m_window);
	updateMouseSprite();
}

void GameMaster::run()
{
	Resources& p2Sin = Resources::getInstance();
	b2World world({ X_GRAVITY, Y_GRAVITY });

	m_gameClock.restart();

	while (m_window.isOpen() && !m_board.end())
	{
		m_board.begin(world);
		m_gameTime = m_totalTime = m_board.getTime();
		bool pressed = true;

		while (m_window.isOpen() && !m_board.getnextLevel())
		{
			for (int32 i = 0; i < LIMIT; ++i)
				world.Step(TIME_STEP, VEL_ITER, POS_ITER);

			sf::Event event;
			sf::Time deltaTime = m_deltaClock.restart();

			while (m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::MouseButtonReleased:
					handleMouseReleased(event, world);				
					break;

				case sf::Event::MouseMoved:
					handleMouseMove();					
					break;

				case sf::Event::KeyPressed:
					handleKeyPress(event.key.code, pressed ,deltaTime);				
					break;

				default:
					break;
				}
			}

			if (event.type == sf::Event::KeyPressed && pressed)
				m_board.movePlayer(event.key.code, deltaTime);

			updateScreen();

			if (m_board.getRestart() || (checkTimer() && m_menu.getDifficulty()))
				handleFailure(world, pressed);

		}
		++m_board;
		if (!m_window.isOpen())
			break;
		else if (!m_board.end())
			levelCompleted(LEVEL_COMPLETED_PIC, NEXT_LEVEL_SOUND);
		else if (m_board.end())
			endGameHandler(world);		
	}


}

void GameMaster::updateTimer()
{
	auto playerTime = m_board.getTime();

	if (playerTime != NO_TIME_LIMIT)
		m_gameTime = int(m_totalTime - m_gameClock.getElapsedTime().asSeconds());
	else
		m_gameTime = NO_TIME_LIMIT;	// Infinity time
}

void GameMaster::updateMouseSprite()
{
	Resources& p2Sin = Resources::getInstance();
	m_mouseSprite.setTexture(p2Sin.getTexture(MOUSE_PIC), true);
	m_mouseSprite.setScale(20 / m_mouseSprite.getLocalBounds().width * 2,
		20 / m_mouseSprite.getLocalBounds().height * 2);
	m_mouseSprite.setColor(sf::Color(255, 255, 255, 128));
}


void GameMaster::drawTryAgain(const sf::Sprite& backGround, MenuButton& btn)
{
	m_window.draw(backGround);
	m_window.draw(m_textTryAgain);
	btn.draw(m_window);
	m_window.display();
	m_window.clear();
}

void GameMaster::setTextTryAgain()
{
	Resources& p2Sin = Resources::getInstance();
	m_textTryAgain.setFont(p2Sin.getFont());
	m_textTryAgain.setFillColor(sf::Color::Red);
	m_textTryAgain.setPosition(50, WINDOW_HEIGHT / 2);
	m_textTryAgain.setCharacterSize(BIG_BUTTON_SIZE+20);
}

void GameMaster::endGameHandler(b2World& world)
{
	levelCompleted(YOU_WIN_PIC, YOU_WIN_SOUND);
	m_board.initCurrentLevel();
	m_board.restart(world);
	m_menu.setDifficulty();
	m_menu.runMenu(m_window);
	m_gameClock.restart();
}

bool GameMaster::checkTimer() const
{
	if (m_gameTime <= 0)
		return true;

	return false;
}

// Try again screen
void GameMaster::tryAgain()
{
	m_window.clear();
	setTextTryAgain();
	int timeLeft = 0;
	sf::Sprite backGround;
	sf::Clock timer;

	Resources& p2Sin = Resources::getInstance();
	MenuButton btn(sf::Vector2f(START_LOC / 2, WINDOW_HEIGHT / 3), EXIT_STRING);

	backGround.setTexture(p2Sin.getTexture(TRY_AGAIN_PIC));
	m_window.display();

	while (m_window.isOpen() && timeLeft >= 0)
	{
		sf::Event event;

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (btn.contains(m_window) && event.mouseButton.button == sf::Mouse::Button::Left))
				m_window.close();

			if (event.type == sf::Event::MouseMoved)
			{
				if (sf::Mouse::getPosition(m_window).x < 0 || sf::Mouse::getPosition(m_window).y < 0)
					continue;
				btn.contains(m_window);
			}
		}

		timeLeft = int(RESET_TIME - timer.getElapsedTime().asSeconds());
		m_textTryAgain.setString(RESET_LEVEL_STRING + std::to_string(timeLeft));
		drawTryAgain(backGround, btn);
	}
}

// update screen
void GameMaster::updateScreen() {

	Resources& p2Sin = Resources::getInstance();
	updateTimer();	// Update the time left for the level
	p2Sin.playMusic(GAME_SOUND, true);
	m_board.handleCollisions();
	handleExtraTime();
	m_board.fire();
	m_window.clear();
	m_board.draw(m_window);
	m_window.draw(m_mouseSprite);
	int level = m_board.getLevel();
	m_dataBar.Draw(m_window, level, m_gameTime, m_menu.getDifficulty());
	m_window.display();
}

void GameMaster::handleExtraTime()
{

	if (m_board.getTimePresent())
		m_totalTime += 10;
}

void GameMaster::levelCompleted(const int& picIndex, const int& soundIndex) {

	Resources& p2Sin = Resources::getInstance();

	sf::Sprite backGround;
	backGround.setTexture(p2Sin.getTexture(picIndex));
	m_window.clear();
	m_window.draw(backGround);
	m_window.display();
	if (m_board.end())
		playMusic(8.0f, soundIndex);
	else
		playMusic(4.0f, soundIndex);

	m_gameClock.restart();
}

void GameMaster::handleKeyPress(const int& key, bool& pressed, sf::Time deltaTime)
{
	if (key == sf::Keyboard::Escape)
		m_window.close();
	else {
		m_board.movePlayer(key, deltaTime);
		pressed = true;
	}
}

void GameMaster::handleMouseReleased(const sf::Event& event, b2World& world)
{
	Resources& p2Sin = Resources::getInstance();

	p2Sin.playMusic(SHOT_SOUND, false);
	m_board.handlePress(m_window, (event.mouseButton.button == sf::Mouse::Left), world);
}

void GameMaster::handleMouseMove()
{
	m_mouseSprite.setPosition((float)sf::Mouse::getPosition(m_window).x, (float)sf::Mouse::getPosition(m_window).y);
	m_board.roratePlayerGun(m_window);
}

void GameMaster::handleFailure(b2World& world, bool& pressed)
{
	tryAgain();
	m_board.restart(world);
	m_gameClock.restart();
	m_totalTime = m_board.getTime();
	pressed = false;
}

void GameMaster::playMusic(const float& time, const int& soundIndex)
{
	Resources& p2Sin = Resources::getInstance();
	p2Sin.playMusic(soundIndex, false);
	sf::Clock clock;
	while (clock.getElapsedTime().asSeconds() < time);
	p2Sin.stop(soundIndex);
}
