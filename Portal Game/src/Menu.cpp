#include "Menu.h"
bool Menu::m_difficulty = false;

Menu::Menu():m_explenation()
{
	startWindow();
}

//=================================RUN MENU===================================
//This function run while the user didnt finish picking all the menu options  
//=============================================================================
void Menu::runMenu(sf::RenderWindow& window)
{
	
	draw(window, m_buttonsMenu);
	startMusic();

	while (true)
	{
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:

				window.close();
				return;

			case sf::Event::MouseMoved:

				if (sf::Mouse::getPosition(window).x < 0 || sf::Mouse::getPosition(window).y < 0)
					continue;

				checkMousOn(event.mouseButton, window);
				break;

			case sf::Event::MouseButtonReleased:

				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					if (m_onDifficulty)
					{
						if (checkDifficulty(window))
							return;
					}

					else
						checkReleased(window);													
				}
					
				break;

			default: 
				break;
			}
		}
		m_onDifficulty ? draw(window, m_DifficultyButtons) : draw(window, m_buttonsMenu);
	}
}
//=============================CHECK RELEASE===================================
//check which of the start buttons the user pressed on
//=============================================================================
void Menu::checkReleased(sf::RenderWindow& window)
{
	if (m_buttonsMenu[FIRST_BUTTON].contains(window)) 
	{
		m_onDifficulty = true;
		music();
	}
	else if (m_buttonsMenu[SECOND_BUTTON].contains(window)) {
		m_music.stop();
		window.close();
		exit(EXIT_SUCCESS);
	}		
	else if (m_buttonsMenu[THIRD_BUTTON].contains(window)) {
		m_music.stop();
		m_explenation.explenation(window);
		m_music.play();
	}
		
}
//============================CHECK MOUSE ON===================================
//check which of the button the mouse is on
//=============================================================================
void Menu::checkMousOn(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (int i = 0; i < m_buttonsMenu.size(); i++)
		m_buttonsMenu[i].contains(window);

	for (int i = 0; i < m_DifficultyButtons.size(); i++)
		m_DifficultyButtons[i].contains(window);
}
//============================GET DIFFICULTY===================================
//return if the user picked hard/easy game
//=============================================================================
bool Menu::getDifficulty() const
{
	return m_difficulty;
}
void Menu::setDifficulty()
{
	m_onDifficulty = false;
}
//=================================MUSIC=======================================
//play and stop the menu music
//=============================================================================
void Menu::music()
{
	if (!m_musicIsOn)
	{
		m_music.play();
		m_musicIsOn = true;
	}
	else
	{
		m_music.pause();
		m_musicIsOn = false;
	}
}
//=============================START WINDOW====================================
//set all the menu buttons
//=============================================================================
void Menu::startWindow()
{
	setBackGround();

	m_buttonsMenu.push_back(*(new MenuButton{sf::Vector2f(START_LOC/2, WINDOW_HEIGHT/3), DIFFICULY_STRING }));
	m_buttonsMenu.push_back(*(new MenuButton{sf::Vector2f(START_LOC/2, WINDOW_HEIGHT/3 + START_LOC), EXIT_STRING }));
	m_buttonsMenu.push_back(*(new MenuButton{sf::Vector2f(START_LOC/2, WINDOW_HEIGHT/3 + START_LOC*2), EXPLENATION_STRING }));
	m_DifficultyButtons.push_back(*(new MenuButton{ sf::Vector2f(START_LOC/2, WINDOW_HEIGHT/3), EASY_STRING }));
	m_DifficultyButtons.push_back(*(new MenuButton{ sf::Vector2f(START_LOC/2, WINDOW_HEIGHT/3 + START_LOC), HARD_STRING}));
}
//==============================START MUSIC====================================
//start the menu music
//=============================================================================
void Menu::startMusic()
{
	if (!m_music.openFromFile("MenuSound.ogg"))
		throw "error in loading music";

	m_music.play();
	m_music.setVolume(MENU_VOLUME);
	m_music.setLoop(true);
}
//=================================DRAW========================================
//draw the menu
//=============================================================================
void Menu::draw(sf::RenderWindow& window, std::vector<MenuButton>& vecButton)
{
	window.draw(m_sprite);

	for (auto& btn : vecButton)
			btn.draw(window);

	window.display();
}
//===========================SET BACKGROUD=====================================
//set the menu background
//=============================================================================
void Menu::setBackGround()
{
	Resources& p2Sin = Resources::getInstance();
	m_sprite.setTexture(p2Sin.getTexture(MENU_PIC), true);
	m_sprite.scale(WINDOW_WIDTH/m_sprite.getGlobalBounds().width,
		WINDOW_HEIGHT/m_sprite.getGlobalBounds().height);
}

bool Menu::checkDifficulty(sf::RenderWindow& window)
{
	if (m_DifficultyButtons[FIRST_BUTTON].contains(window))
	{
		m_difficulty = false;
		return true;
	}

	else if (m_DifficultyButtons[SECOND_BUTTON].contains(window)) 
	{
		m_difficulty = true;
		return true;
	}
	
	return false;
}