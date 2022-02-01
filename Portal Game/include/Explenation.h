#pragma once
#include "Resources.h"
#include "Const.h"

class Explenation
{
public:
	Explenation();
	void explenation(sf::RenderWindow& window);
private:
	void set(const std:: string &str , sf::Text& text, const int& x, const int& y, sf::Color color);
	sf::Sprite m_backgroundSprite;
	sf::Text m_exptext , m_countinueText;
};
