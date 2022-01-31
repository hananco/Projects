#include "Pipe.h"
#include <iostream>

Pipe::Pipe(const std::vector <int>& direction, const sf::Vector2f& postion )
	:m_direction(direction) ,m_position(postion) ,m_typePipe(direction[PIPE_TYPE]) 
{	

	if (m_typePipe == TAP)
		m_isFul = true;
	setSpriteTexsture( m_typePipe);
}

void Pipe::setSpriteTexsture(const int& index)
{
	Singleton& p2singleton = Singleton::getInstance();
	m_objct.setTexture(*p2singleton.getTexture(index), true);
	m_objct.setOrigin(m_objct.getTexture()->getSize().x * 0.5, m_objct.getTexture()->getSize().y * 0.5);

	m_objct.setScale(0.75, 0.75);
	m_objct.setPosition(m_position);
}

sf::Sprite Pipe::getSprite() const
{
	return m_objct;
}

sf::Vector2f Pipe::getPosition() const
{
	return m_objct.getPosition();
}

bool Pipe::collision(const float& posX, const float& posY) const
{
	sf::Vector2f pos(posX, posY);
	return m_objct.getGlobalBounds().contains(pos);
}

void Pipe::rotatePipe(const int& dircition)
{

	if (dircition == 0)
		m_objct.rotate(90);
	else
		m_objct.rotate(-90);

	setNewDirction();
}

void Pipe::setIsEmpte()
{
	Singleton& sin = Singleton::getInstance();

	m_isFul = false;
	m_objct.setTexture(*sin.getTexture(m_typePipe));

	
}

bool Pipe::checkWaterInNeighbor( Pipe& pipe )
{
	sf::Vector2f posNeighbor;
	
		posNeighbor = pipe.getPosition();
		if (pipe.getIsFul() && !m_isFul )
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
				if (getPosition().x > posNeighbor.x ) 
					return CheckDirection(WEST, EAST, pipe);
				else 
					return CheckDirection(EAST, WEST,  pipe);
				
			}
		}		
	
}

bool Pipe::CheckDirection(const int& myDirction, const int& neighborDirctio , Pipe& pipe)
{
	if (m_direction[myDirction] == 1 && pipe.checkBitInDirction(neighborDirctio) == 1)
	{
		m_isFul = true;
		setSpriteTexsture( m_typePipe + 4);	
		return true;
	}
	return false;
}

bool Pipe::checkBitInDirction(const int& index) const
{
	return m_direction[index] == 1;
}

bool Pipe::getIsFul()const
{
	return m_isFul;
}

bool Pipe::checkIfNeighbor(const sf::Vector2f& pos)const
{
	int dalta = 50;
	if (collision(pos.x + dalta, pos.y) ||
		collision(pos.x - dalta, pos.y) ||
		collision(pos.x, pos.y + dalta) ||
		collision(pos.x, pos.y - dalta))
		return true;

	return false;
}

int Pipe::getTypePipe() const
{
	return m_typePipe;
}



void Pipe::setNewDirction()
{
	//the func return the new dirction of this pipe after the rotation
	int place = m_objct.getRotation();
	place = (place % 89);// 90 degree  is 1 180 degree 2 270 degree is 3 end 360 degree is 0

	Singleton& p2singleton = Singleton::getInstance();
	m_direction.clear();
	m_direction = p2singleton.getNweDirction(m_typePipe , place);
}
