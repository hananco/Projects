#include "Trampoline.h"
bool Trampoline::m_registerit = Creator::registerit('T', [](const char& a, const sf::Vector2f& b, const sf::Vector2f& c, b2World& e) ->std::shared_ptr <GameObject> { return std::make_shared <Trampoline>(a, b, c, e); });
//==============================CONSTRUCTOR====================================
Trampoline::Trampoline(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world)
	:FixedObject(index,loc, objSize, Resources::getInstance().getTexture(TRAMPOLINE_PIC), world){}
//====================HANDLE COLLISION USING DOUBLE DISPATCH===================
void Trampoline :: handleCollision(GameObject& gameObject)
{
    if (&gameObject == this) return;
    gameObject.handleCollision(*this);
}
//====================HANDLE COLLISION WITH PLAYER, JUMPING====================
void Trampoline :: handleCollision(Player& gameObject) 
{
    trampolineJumping(gameObject);
}
//====================HANDLE COLLISION WITH BOX, JUMPING=======================
void Trampoline::handleCollision(Box& gameObject)
{
    trampolineJumping(gameObject);
}
//============================MAKE THE OBJECT JUMP=============================
void Trampoline::trampolineJumping(GameObject& obj) {

    float Ydis = abs(m_sprite.getPosition().y - obj.getPosition().y);
    float xdis = abs(m_sprite.getPosition().x - obj.getPosition().x);
    if (Ydis > 0 && Ydis <= m_sprite.getGlobalBounds().height && xdis < m_sprite.getGlobalBounds().width)
        obj.jump();
}
