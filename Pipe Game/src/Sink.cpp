#include "..\include\Sink.h"
#include <iostream>
Sink::Sink(const std::vector<int>& direction, const sf::Vector2f& postion)
	:m_direction(direction), m_position(postion), m_typePipe(direction[PIPE_TYPE])
{

	setSpriteTexsture(m_typePipe);
	rotateSinkForDirction();
}

void Sink::setSpriteTexsture(const int& index)
{
	Singleton& p2singleton = Singleton::getInstance();
	m_objct.setTexture(*p2singleton.getTexture(index), true);
	m_objct.setOrigin(m_objct.getTexture()->getSize().x * 0.5, m_objct.getTexture()->getSize().y * 0.5);

	m_objct.setScale(0.75, 0.75);
	m_objct.setPosition(m_position);
}


sf::Sprite Sink::getSprite() const
{
	return m_objct;
}

sf::Vector2f Sink::getPosition() const
{
	return  m_objct.getPosition();;
}

bool Sink::collision(const float& posX, const float& posY)const
{
 	sf::Vector2f pos(posX, posY);
	return m_objct.getGlobalBounds().contains(pos); ;
}

bool Sink::getIsFul() const
{
	return m_isFul;
}

bool Sink::checkWaterInNeighbor( Pipe& pipe) 
{
	sf::Vector2f posNeighbor;

	posNeighbor = pipe.getPosition();
	if (pipe.getIsFul() )
	{
		if (getPosition().x == posNeighbor.x)
		{
			if (getPosition().y > posNeighbor.y)
				return CheckDirection(NORTH, SOUTH, pipe);
			else
				return CheckDirection(SOUTH, NORTH, pipe);
		}
		else
		{
			if (getPosition().x > posNeighbor.x)
				return CheckDirection(WEST, EAST, pipe);
			else
				return CheckDirection(EAST, WEST, pipe);
		}
	}	
}

bool Sink::CheckDirection(const int& myDirction, const int& neighborDirctio, Pipe& pipe)
{
	if (m_direction[myDirction] == 1 && pipe.checkBitInDirction(neighborDirctio) == 1)
	{
		m_isFul = true;
		return true;
	}
	return false;
}

bool Sink::checkIfNeighbor(const sf::Vector2f& pos) const
{
	int dalta = 100;
	if (collision(pos.x + dalta, pos.y) ||
		collision(pos.x - dalta, pos.y) ||
		collision(pos.x, pos.y + dalta) ||
		collision(pos.x, pos.y - dalta))
		return true;

	return false;
}

void Sink::rotateSinkForDirction()
{
	for (int i = 0; i < m_direction.size()-1; i++)
		if (m_direction[i] == 1)
			m_objct.rotate(i * 90 +3*90);

}
