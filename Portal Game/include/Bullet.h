#pragma once
#include "Resources.h"

class Bullet {
public:
	Bullet(const sf::Vector2f& size, const sf::Vector2f& start,
		const sf::Vector2f& direction);
	void fire();
	void draw(sf::RenderWindow&);

	sf::Vector2f getPos()const;
	sf::Vector2f getStartPos()const;
	void returnBack();
	void returnToStart();
private:
	sf::RectangleShape m_bullet;
	sf::Vector2f m_startPosition, m_direction, m_curPos;
};