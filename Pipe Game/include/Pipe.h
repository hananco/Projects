#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Singleton.h"
#include "Globals.h"
#include "Pipe.h"

class Pipe
{
public:
	Pipe(const std::vector <int>& direction , const sf::Vector2f & postion );
	void setSpriteTexsture(const int& index);//set the texstur
	sf::Sprite getSprite() const;// return the sprite
	sf::Vector2f getPosition()const;// return the postion of the object
	bool collision(const float& posX , const float& posY)const;//check if there is a collision
	void rotatePipe(const int& dircition);// rotate the object
	void setNewDirction();// return the new direction of the object
	void setIsEmpte();// set the bool of isfull to be false
	bool checkWaterInNeighbor( Pipe& pipe);// check if in the neighbor we have a water
	//check if ther is a 1 for a mach between the are pipe end the pipe we got
	bool CheckDirection(const int & myDirction , const int& neighborDirctio, Pipe& pipe);
	bool checkBitInDirction(const int& index) const;//return if the pipe in this indix on the dirction have a 1
	bool getIsFul()const;//return  the bool for know if thre is a water in the pipe
	bool checkIfNeighbor(const sf::Vector2f& position)const;// check if this pipe is a neighbor of the pipe we got is postion
	int getTypePipe()const;//return the pipe type
protected:
	


private:
	int m_typePipe = 0;
	sf::Vector2f m_position;
	sf::Sprite m_objct;
	std::vector <int> m_direction;//have the direction of the open pipe
	bool m_isFul = false;

};

