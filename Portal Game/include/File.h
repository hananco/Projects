#pragma once
#pragma warning(push, 0)
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#pragma warning(pop)
/* CLASS FILE : 
* ============================================================================
* This class is responsible to read the level file , it also save the location
* of each object at the file
*/

class File {
public:
	File();
	std::pair<std::vector <char>, std::vector <sf::Vector2f>> readLevel(const int& indexLevel);
	sf::Vector2f getSize() const;
	int getTime() const;

private:
	void openFile(const int&);
	bool charIsValid(const char&) const;
	
	std::ifstream m_file;
	sf::Vector2f m_size;
	int m_row, m_col, m_time;
};