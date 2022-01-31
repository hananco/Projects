#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include"Singleton.h"
#include "Pipe.h"
class Sink
{
public:
	Sink(const std::vector <int>& direction, const sf::Vector2f& postion);
	~Sink() = default;
	void setSpriteTexsture(const int& index);//set the texstur
	bool CheckDirection(const int& myDirction, const int& neighborDirctio, Pipe& pipe);
	sf::Sprite getSprite() const;// return the sprite
	sf::Vector2f getPosition()const;// return the postion of the object
	bool collision(const float& posX, const float& posY)const;//check if there is a collision
	bool getIsFul() const;//return  the bool for know if thre is a water in the pipe
	bool checkWaterInNeighbor( Pipe& pipe) ;// check if in the neighbor we have a water
	// check if this pipe is a neighbor of the pipe we got
	bool checkIfNeighbor(const sf::Vector2f& pos)const ;
	//rotate the sink as per the dirction  (if the dirction is 10011 so the sink be to the left )
	void rotateSinkForDirction();

private:
	int m_typePipe ;
	sf::Vector2f m_position;
	sf::Sprite m_objct;
	std::vector <int> m_direction;
	bool m_isFul = false;

};

