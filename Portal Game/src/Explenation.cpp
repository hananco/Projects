#include "Explenation.h"
//==============================CONSTRUCTOR====================================
Explenation::Explenation()
{
	Resources& p2Sin = Resources::getInstance();
	m_backgroundSprite.setTexture(p2Sin.getTexture(EXPLENATION_PIC));
	set("", m_exptext, START_LOC, START_LOC, sf::Color::White);
	set(CONTINUE_STRING, m_countinueText, START_LOC, WINDOW_HEIGHT - START_LOC, sf::Color::Red);
	m_backgroundSprite.setScale(WINDOW_WIDTH / m_backgroundSprite.getGlobalBounds().width,
		WINDOW_HEIGHT / m_backgroundSprite.getGlobalBounds().height);
}
void Explenation::explenation(sf::RenderWindow& window) {

	sf::Clock clock;
	window.draw(m_backgroundSprite);
	Resources& p2Sin = Resources::getInstance();
	p2Sin.playMusicRegular(EXPLENATIONS_SOUND, true);
	for (auto& str : EXPLENATION_STRINGS) {
		m_exptext.setString("");
		for (int i = 0; i < str.size(); i++) {
			while (clock.getElapsedTime().asSeconds() < 0.1f);
			clock.restart();
			m_exptext.setString(m_exptext.getString() + str[i]);
			window.clear();
			window.draw(m_backgroundSprite);
			window.draw(m_exptext);
			window.display();
		}
		window.draw(m_countinueText);
		window.display();

		while (window.isOpen()) {
			sf::Event event;
			window.pollEvent(event);
			if (event.type == sf::Event::MouseButtonPressed)
				break;
		}
	}
	p2Sin.stop(EXPLENATIONS_SOUND);
}
void Explenation :: set(const std::string& str ,sf::Text& text, const int& x, const int& y, sf::Color color) {

	Resources& p2Sin = Resources::getInstance();
	text = sf::Text{ str, p2Sin.getFont() };
	text.setPosition(x, y);
	text.setCharacterSize(NORAML_BUTTON_SIZE);
	text.setFillColor(color);
}