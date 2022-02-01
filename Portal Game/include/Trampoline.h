#pragma once
#include "FixedObject.h"
#include "Box.h"
class ButtonFloor;
class Wall;
class Player;
class Acid;
class Elevator;
class TimePresent;
class Button;
class BadLaser;

class Trampoline :public FixedObject
{
public:
    Trampoline(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world);
    void trampolineJumping(GameObject& obj);
    //Resources& p2Sin = Resources::getInstance();
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Player& gameObject) override;
    void handleCollision(Box& gameObject) override;
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
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