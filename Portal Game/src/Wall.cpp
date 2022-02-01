#include "Wall.h"
bool Wall::m_registerit = Creator::registerit('#', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c,b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Wall>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Wall::Wall(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,  b2World& world)
	:FixedObject(index, loc,sf::Vector2f(objSize.x + 8 , objSize.y), Resources::getInstance().getTexture(WALL_PIC), world)
{
	m_save = m_sprite;
}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Wall:: handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	gameObject.handleCollision(*this);
}
//===================================PRESS=====================================
//THIS FUNCTION IS BEEN CALLED WHEN THE PLAYER WANT TO OPEN PORTAL AT THIS WALL,
//RETURN TRUE BECAUSE WALL IS AN OBJECT THAT CAN BE PORTAL
//=============================================================================
bool Wall :: Press(const bool& enter)
{
	Resources& p2Sin = Resources::getInstance();

    if (enter) 
        m_sprite.setTexture(p2Sin.getTexture(ENTER_PORTAL_PIC));
    else 
        m_sprite.setTexture(p2Sin.getTexture(EXIT_PORTAL_PIC));
    return true;
}
//===============================NOT PRESSED====================================
//THIS FUNCTION IS BEEN CALLED WHEN THE PLAYER WANT TO OPEN OTHER PORTAL OR TO
//CANCEL THIS ONE
//=============================================================================
void Wall :: NotPressed()
{
    m_sprite = m_save;
}