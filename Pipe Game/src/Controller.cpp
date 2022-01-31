#include "Controller.h"
#include <iostream>
#include <stdlib.h>

Controller::Controller()
	: m_window(sf::VideoMode(WIDTH, HEIGHT), "game window")
{
	
}

Controller::~Controller()
{
}

void Controller::run()
{
	int levelIndex = 0, counterTap = 0;
	readLeval();
	m_board.statusLine();

	m_board.makeBoard(m_level[levelIndex]);
	while (m_window.isOpen())
	{


		sf::Event event;
		while (m_window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				m_window.close();
				break;
			}


			if (event.type == sf::Event::MouseButtonReleased)
			{

				if (event.type == sf::Event::MouseButtonReleased)
					if (event.mouseButton.button == sf::Mouse::Right)
						m_board.rotateObject(event.mouseButton.x, event.mouseButton.y, RIGHT, counterTap);
					else
						m_board.rotateObject(event.mouseButton.x, event.mouseButton.y, LEFT, counterTap);
			}
			m_board.textStatusLine(levelIndex + 1, counterTap);
			m_board.checkNeighbors();
			m_window.clear();
			m_board.drawWindow(m_window);
			m_window.display();
			m_board.setIsFull();
			if (m_board.checkLevelCompleted())
			{
				counterTap = 0;
				m_board.clearBoard();
				levelIndex++;
				printEndLevel(m_window, 11);
				if (levelIndex == SUM_OF_LEVEL)
				{
					printEndLevel(m_window, 12);
					break;
				}
				m_board.makeBoard(m_level[levelIndex]);
				break;
			}

		}

		if (levelIndex == SUM_OF_LEVEL)
			break;

	}
}

void Controller::printEndLevel(sf::RenderWindow& window, const int& index)
{

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	Singleton& r = Singleton::getInstance();
	sf::Sprite s;
	s.setTexture(*r.getTexture(index), true);
	m_window.clear();
	m_window.draw(s);
	if(index != 12)// index = 12 is the index for the win game
		m_board.printStatusLinr(window);
	m_window.display();
	std::this_thread::sleep_for(std::chrono::seconds(2));

}

void Controller::readLeval()
{
		File file;
		while (!file.getEof())
		{
			Level level = file.readLevalFromFile();
			m_level.push_back(level);
		}
}
