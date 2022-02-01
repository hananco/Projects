#pragma once
#include "GameObject.h"
#include "Creator.h"

class FixedObject : public GameObject
{
public:
    using GameObject::GameObject;
    FixedObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world) :
        GameObject(index, loc, objSize, texture, world, false) {};
};