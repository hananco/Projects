#include "Acid.h"
bool Acid::m_registerit = Creator::registerit('A', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Acid>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Acid::Acid(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
	:FixedObject(index, loc , objSize, Resources::getInstance().getTexture(ACID_PIC), world) {}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Acid :: handleCollision(GameObject& gameObject) 
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}