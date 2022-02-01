#include "ButtonFloor.h"
bool ButtonFloor::m_registerit = Creator::registerit('-', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <ButtonFloor>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
ButtonFloor :: ButtonFloor(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world) :
    FixedObject(index, loc, objSize , Resources::getInstance().getTexture(BUTTON_FLOOR_PIC), world) {
    setAble(true);
}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void ButtonFloor :: handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}