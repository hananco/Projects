#pragma once
#include "Player.h"
class Wall;
class BadLaser;
class Acid;
class Elevator;
class Button;
class Trampoline;
class TimePresent;
class ButtonFloor;

class Box :public UnFixedObject
{
public:
    Box(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world);
    void handlePress(Player& gameObject) override;
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Player& gameObject) override {}
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
    void handleCollision(Box& gameObject) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handleCollision(ButtonFloor& gameObject) override {/*ignore*/ }
    void handleCollision(BadLaser& gameObject) override {/*ignore*/ }
private:
    static bool m_registerit;
};