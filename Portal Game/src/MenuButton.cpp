#include "MenuButton.h"
//================================CONSTRACTOR==================================
//Set the position of the button text
//=============================================================================
MenuButton::MenuButton(const sf::Vector2f& position, const std::string& text)
{
	Resources& p2Sin = Resources::getInstance();
	m_text = sf::Text{ text, p2Sin.getFont() };
	m_text.setPosition(position);
	m_text.setCharacterSize(NORAML_BUTTON_SIZE);
	m_textRec = m_text.getGlobalBounds();
}
//====================================DRAW=====================================
//Draw the button in the menu
//=============================================================================
void MenuButton::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}
//=================================CONTAINS====================================
//Check if this button has been pressed/go throw by the user (by mouse location)
//=============================================================================
bool MenuButton::contains(sf::RenderWindow& window)
{
	bool result = m_textRec.contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
	if (result)
	{
		if (m_play) {
			Resources& p2Sin = Resources::getInstance();
			p2Sin.playMusicRegular(MENU_BUTTON_SOUND, false);
		}
		setButton(sf::Color::Red, false , BIG_BUTTON_SIZE);
	}
	else 
		setButton(sf::Color::White , true ,  NORAML_BUTTON_SIZE);

	return result;
}
void MenuButton::setButton(sf::Color color, const bool& on, const int& size) {
	m_text.setFillColor(color);
	m_text.setCharacterSize(size);
	m_play = on;
}