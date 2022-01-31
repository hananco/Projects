#include "Board.h"
#include <iostream>
#include <cmath>
Board::Board()
	:m_statusLine(sf::Vector2f(250 , 700) ),m_sink(std::vector{ 0,0,0,0,1 }, sf::Vector2f(0, 0))// default 
{
	m_textStatusLine.resize(2);
	Singleton& texsture = Singleton::getInstance();
	m_background.setTexture(*texsture.getTexture(10), true);
	
}

void Board::makeBoard(const Level& level)
{
	int x = 0, y = 0;
	int sizeRow = level.getRow();
	int sizeCol = level.getCol();
	int size = sizeCol * sizeRow;
	m_MaxSize = std::max(sizeCol, sizeRow);
	float widthObjct = (((float)WIDTH -620 ) / level.getRow());
	float heightObjct = (((float)HEIGHT - DETAILS - 220) / level.getRow());


	for (int i = 0; i < size; i++)
	{
	
		x = (x % sizeCol);
		if (i % sizeCol == 0 && i != 0)
			y++;
		sf::Vector2f pos(x * widthObjct + (WIDTH / 4), y * heightObjct + 120);
		sf::Vector2i size(x, y);
		if (level.getWichObject(i, 4) == SINK)
			m_sink = Sink(level.getPipe(i), pos);
		else 
		{
			Pipe temp(level.getPipe(i), pos);
			m_pipes.emplace_back(temp);
		}
		x++;
				
	}

}
void Board::checkNeighbors()
{
	sf::Vector2f pos;
	for (int k = 0; k < m_MaxSize; k++)
	{
		for (int i = 1; i < m_pipes.size(); i++)
		{
			for (int j = 0; j < m_pipes.size(); j++)
			{
				pos = m_pipes[j].getPosition();
				if (i != j)
				{
					if (m_pipes[i].checkIfNeighbor(pos) && m_pipes[i].checkWaterInNeighbor(m_pipes[j]))
						break;
					else if (m_pipes[i].getIsFul())
						m_pipes[i].setIsEmpte();
				}
				if (m_sink.checkIfNeighbor(pos) && m_sink.checkWaterInNeighbor(m_pipes[j]))
				{
					
					break;
				}
					
			}

		}
	}
	
}
void Board::statusLine()
{
	Singleton& font = Singleton::getInstance();

	m_statusLine.setPosition(WIDTH - 200, 0);
	m_statusLine.setFillColor(sf::Color::Cyan);
	m_statusLine.setOutlineColor(sf::Color::White);
	m_statusLine.setOutlineThickness(3);


	for (auto i = 0; i < m_textStatusLine.size(); i++)
		m_textStatusLine[i].setFont(*font.getFont());

	for (auto i = 0; i < m_textStatusLine.size(); i++) {
		m_textStatusLine[i].setPosition(sf::Vector2f(WIDTH - 170, 100 * (i + 1)));
		m_textStatusLine[i].setCharacterSize(40);
		m_textStatusLine[i].setColor(sf::Color::Black);
	}

}
void Board::textStatusLine(const int& level, const int& counterTap)
{
	std::vector<std::string> strings;

	strings.resize(2);
	strings[0] = "Level: ";
	strings[0].append(std::to_string(level));

	strings[1] = "Tap: ";
	strings[1].append(std::to_string(counterTap));

	m_textStatusLine[0].setString(strings[0]);
	m_textStatusLine[1].setString(strings[1]);

}
void Board::drawWindow(sf::RenderWindow& window)
{
	window.draw(m_background);

	for (int i = 0; i < m_pipes.size(); i++)
		window.draw(m_pipes[i].getSprite());
	window.draw(m_sink.getSprite());

	printStatusLinr(window);

}
void Board::rotateObject(const float& posx, const float& posy, const int& dirction , int &tap)
{
	for (int i = 0; i < m_pipes.size(); i++)
	{
		if (m_pipes[i].collision(posx, posy))
		{
			tap++;
			m_pipes[i].rotatePipe(dirction);
			break;
		}
			
	}
}

void Board::setIsFull()
{
	for (int i = 1; i < m_pipes.size(); i++)
	{
		if (m_pipes[i].getIsFul())
			m_pipes[i].setIsEmpte();
	}
}

bool Board::checkLevelCompleted() const
{
	return m_sink.getIsFul();
}

void Board::clearBoard()
{
	m_pipes.clear();
}

void Board::printStatusLinr(sf::RenderWindow& window)
{
	window.draw(m_statusLine);

	for (int j = 0; j < m_textStatusLine.size(); j++)
		window.draw(m_textStatusLine[j]);
}

