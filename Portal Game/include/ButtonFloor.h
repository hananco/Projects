#pragma once
#include "FixedObject.h"
class Player;
class Acid;
class Wall;
class Box;
class Elevator;
class Button;
class Trampoline;
class TimePresent;
class BadLaser;

class ButtonFloor :public FixedObject
{
public:
    //Resources& p2Sin = Resources::getInstance();
    ButtonFloor(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world);
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
