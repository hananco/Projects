#include "Bullet.h"
//==============================CONSTRUCTOR====================================
Bullet::Bullet(const sf::Vector2f& size, const sf::Vector2f& start,
	const sf::Vector2f& direction) :m_startPosition(start),
	m_direction(direction)
{
	m_bullet.setSize(size);
	m_bullet.setFillColor(sf::Color::Red);
	m_bullet.setPosition(m_startPosition);
	m_curPos = m_startPosition;
}

void Bullet::fire()
{
	m_bullet.move(m_direction);
	m_curPos = m_bullet.getPosition();
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(m_bullet);
}
sf::Vector2f Bullet::getPos()const {
	return m_curPos;
}
sf::Vector2f Bullet::getStartPos()const {
	return m_startPosition;
}
void Bullet::returnBack() {
	m_bullet.move(-m_direction.x , 0);
}
void Bullet::returnToStart() {
	m_bullet.setPosition(m_startPosition);
}
