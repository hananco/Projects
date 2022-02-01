#include "Fence.h"
bool Fence::m_registerit = Creator::registerit('*', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c,  b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Fence>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Fence::Fence(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
    :FixedObject(index, loc, sf::Vector2f(objSize.x + 8, objSize.y), Resources::getInstance().getTexture(FENCE_PIC), world)
{}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Fence::handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}