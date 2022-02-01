#pragma once
#include "FixedObject.h"
class Player;
class Wall;
class Box;
class BadLaser;
class Acid;
class Button;
class Trampoline;
class TimePresent;
class ButtonFloor;
class Elevator :public FixedObject
{
public:
    Elevator(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world);
    //Resources& p2Sin = Resources::getInstance();
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Player& gameObject) override { m_levelEnd = true; }
    void handleCollision(ButtonFloor& gameObject) override {/*ignore*/ }
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
    void handleCollision(Box& gameObject) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handleCollision(BadLaser& gameObject) override {/*ignore*/ }
private:
    static bool m_registerit;
};