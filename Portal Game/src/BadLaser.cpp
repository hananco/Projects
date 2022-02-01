#include "BadLaser.h"
bool BadLaser::m_registerit = Creator::registerit('G', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <BadLaser>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
BadLaser::BadLaser(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
	:FixedObject(index, loc, objSize, Resources::getInstance().getTexture(LAZER_HOUSE_PIC), world)
{
	m_shotDirection = (loc.x > WINDOW_WIDTH / 2) ? sf::Vector2f{-BULLET_MOVE, 0} :
		sf::Vector2f{BULLET_MOVE, 0} , m_sprite.setRotation(ANGLE);
}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void BadLaser::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
//==================================FIRE======================================
void BadLaser::fire()
{
	if (m_bullets.size() < WINDOW_WIDTH / BULLET_LEGNTH) {

		if (m_bullets.size() > 0 && m_totalTime.getElapsedTime().asSeconds() > 5.0f) {
			m_bullets.erase(m_bullets.begin()); //remove one bullet
			m_bullets.begin()->returnToStart();
		}

		Bullet newBullet(sf::Vector2f(BULLET_LEGNTH, BULLET_WIDTH), sf::Vector2f(m_body->GetPosition().x + (m_shotDirection.x * BULLET_WIDTH*3),
			m_body->GetPosition().y), m_shotDirection);
		m_bullets.push_back(newBullet);

		if (m_inPortal) {
			Bullet newBullet(sf::Vector2f(BULLET_LEGNTH, BULLET_WIDTH), sf::Vector2f(m_portLoc.x + (m_portDir.x * BULLET_WIDTH*3),
				m_portLoc.y), m_portDir);
			m_bullets.push_back(newBullet);
		}
	}
	else {
		m_bullets.erase(m_bullets.begin());
		if (m_inPortal)
			m_bullets.erase(m_bullets.begin());
	}
}

void BadLaser::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_body->GetPosition().x, m_body->GetPosition().y);
	window.draw(m_sprite);

	for (auto& bullet : m_bullets)
	{
		bullet.fire();
		if (m_callBack.rayCastValid(bullet.getStartPos(), bullet.getPos())) {
			m_world->RayCast(&m_callBack, b2Vec2{ bullet.getStartPos().x ,bullet.getStartPos().y },
				b2Vec2{ bullet.getPos().x ,bullet.getPos().y });
			m_callBack.path() ? bullet.draw(window) : bullet.returnBack();
		}
		m_callBack.set(m_body, m_body);
	}
}

bool BadLaser::doesFire() {
	if (m_clock.getElapsedTime().asSeconds() > 0.5f){
		m_clock.restart();
		return true;
	}
	return false;
}
bool BadLaser::collision(const b2Body* body) {

	for (auto& bullet : m_bullets)
	{
		if (m_callBack.rayCastValid(bullet.getStartPos() ,bullet.getPos()))
		{
			m_world->RayCast(&m_callBack, b2Vec2{bullet.getStartPos().x ,bullet.getStartPos().y },
				b2Vec2{ bullet.getPos().x ,bullet.getPos().y });
			if (!m_callBack.path() && m_callBack.getcoliision() == body) 
				return true;
		}
		m_callBack.set(m_body, m_body);
	}
	return false;
}
void BadLaser::port(const b2Vec2& pos) {

	m_portLoc = { pos.x , pos.y };
	m_portDir = (pos.x > WINDOW_WIDTH / 2) ? sf::Vector2f{-BULLET_MOVE, 0} :
				sf::Vector2f{BULLET_MOVE, 0};
	m_inPortal = true;
}
void BadLaser::resetBody() {

	GameObject::resetBody();
	m_bullets.clear();
	m_clock.restart();
	m_totalTime.restart();
}
void BadLaser::notPort() {

	m_inPortal = false;
}