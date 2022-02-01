#include "UnfixedObject.h"
//==============================CONSTRUCTOR====================================
UnFixedObject ::UnFixedObject (const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world) :
    GameObject(index, loc, objSize, texture, world, true) {}
//==================================PORT=======================================
//THIS FUNCTION DOES THE PORTAL TRANSITION, ONLY DYNAMIC OBJECTS CAN GO THROW 
//=============================================================================
void UnFixedObject::port(const b2Vec2& pos)
{
    sf::Vector2f size(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
    m_body->SetTransform(pos, m_body->GetAngle());

    if (pos.x <= size.x)
        m_body->SetTransform({ pos.x + size.x,pos.y }, m_body->GetAngle());
    if (pos.x >= WINDOW_WIDTH - size.x)
        m_body->SetTransform({ pos.x - size.x,pos.y }, m_body->GetAngle());
    if (pos.y <= size.y)
        m_body->SetTransform({ pos.x ,pos.y + size.y }, m_body->GetAngle());
    if (pos.y >= WINDOW_HEIGHT - size.y - 80)
        m_body->SetTransform({ pos.x ,pos.y - size.y }, m_body->GetAngle());

    m_body->SetAwake(true);
}
//==================================JUMP=======================================
//THIS FUNCTION DOES THE TRAMPOLINE JUMPING, ONLY DYNAMIC OBJECTS CAN JUMP
//=============================================================================
void UnFixedObject :: jump()
{
    m_body->ApplyLinearImpulse({ 0,JUMP_POWER}, m_body->GetPosition(), true);
    play(TRAMPOLINE_SOUND, false);
}
