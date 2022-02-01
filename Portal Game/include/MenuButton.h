#pragma once
#include "Resources.h"
#include "Const.h"

/* CLASS MENU_BUTTON :
* ============================================================================
* This class is used by the menu class and each object from this class is 
* button on the menu
*/

class MenuButton {
public:
	MenuButton(const sf::Vector2f&, const std::string&);
	void draw(sf::RenderWindow&);
	bool contains(sf::RenderWindow&);
	
private:
	void setButton(sf::Color color, const bool& on, const int& size);
	sf::Text m_text;
	sf::FloatRect m_textRec;
	bool m_play = false;
};