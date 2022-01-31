#pragma once
#include "Level.h"
#include "Globals.h"
#include "Pipe.h"
#include "Sink.h"
class Board
{
public:
	Board();
	void makeBoard(const Level& level);//make the object in this level
	//func thet check if the object are neighber end if the are so if thre is a water in the neighbor
	void checkNeighbors();
	void drawWindow(sf::RenderWindow& window);//draw the object and end the status line on the window
	//A function that checks on which object the mouse presses and then rotates it
	void rotateObject(const float& posx, const float& posy, const int& dirction, int & tap);
	//func thet return the all object to be unfull 
	void setIsFull();
	//check if we have a water in sink
	bool checkLevelCompleted() const;
	//set the position and font for the status line
	void statusLine();
	//set the text to the status line
	void textStatusLine(const int& level, const int& counterTap);
	//clear the vector to the nex level
	void clearBoard();
	////print the status line
	void printStatusLinr(sf::RenderWindow& window);
private:
	sf::Font m_font;
	sf::RectangleShape m_statusLine;
	sf::Sprite m_background;
	std::vector<sf::Text> m_textStatusLine;
	int m_MaxSize = 0;//for the raeng loop
	std::vector <Pipe> m_pipes;// vector for the object of pipe end tap
	Sink m_sink;
};

