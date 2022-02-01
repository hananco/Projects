#pragma once
#include "Resources.h"

class DataBar
{
public:
	DataBar();
	void Draw(sf::RenderWindow&, const int&, const int& time, const bool& difficulty);

private:
	std::vector<sf::Text> m_texts;
	sf::RectangleShape m_toolBar;
	std::vector<std::string> m_strings;
};
