#pragma once
#include "GameObject.h"
#include "Creator.h"
class UnFixedObject : public GameObject
{
public:
    using GameObject::GameObject;
    UnFixedObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world);
    void port(const b2Vec2& pos) override;
    void jump()override;
};