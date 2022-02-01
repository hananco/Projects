#include "Elevator.h"
bool Elevator::m_registerit = Creator::registerit('E', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Elevator>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Elevator::Elevator(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
	:FixedObject(index, loc, objSize, Resources::getInstance().getTexture(ELEVATOR_PIC), world) {}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Elevator :: handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}
