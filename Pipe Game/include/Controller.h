#pragma once
#include "File.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
#include "Globals.h"
#include "Level.h"
#include "Board.h"
#include <chrono>
#include <thread>

class Controller
{
public:
	Controller();
	~Controller()  ;
	void run();

private:

	void printEndLevel(sf::RenderWindow& window, const int& index);//print the win window when we end level 
	void readLeval();//go to file end read to the end
	std::vector<Level> m_level;// vector thet holder the level
	sf::RenderWindow m_window;
	Board m_board;
};

