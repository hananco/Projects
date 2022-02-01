#include "Box.h"

bool Box::m_registerit = Creator::registerit('B', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Box>(a, b, c,  e); });
//==============================CONSTRUCTOR====================================
Box::Box(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
    :UnFixedObject(index, loc, objSize, Resources::getInstance().getTexture(BOX_PIC), world) {}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Box :: handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}

void Box::handlePress(Player& gameObject)
{
    gameObject.box(*m_body);
}