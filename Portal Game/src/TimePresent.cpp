#include "TimePresent.h"
bool TimePresent::m_registerit = Creator::registerit('W', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <TimePresent>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
TimePresent::TimePresent(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
	:FixedObject(index,loc, objSize, Resources::getInstance().getTexture(WATCH_PIC), world){}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void TimePresent :: handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    if (dynamic_cast <Player*> (&gameObject))
    {
        gameObject.handleCollision(*this);
        m_isDisposed = true;
        m_body->SetEnabled(false);
    }
    
}
