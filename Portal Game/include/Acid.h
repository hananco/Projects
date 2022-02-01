#pragma once
#include "FixedObject.h"
class Creator;
class Player;
class Wall;
class Player;
class Box;
class BadLaser;
class Elevator;
class Button;
class Trampoline;
class TimePresent;
class ButtonFloor;

class Acid :public FixedObject
{
public:
    Acid(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world);
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Player& gameObject) override {/*ignore*/ }
    void handleCollision(Wall& gameObject) override {/*ignore*/}
    void handleCollision(Box& gameObject) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(ButtonFloor& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handleCollision(BadLaser& gameObject) override {/*ignore*/ }
private:
    static bool m_registerit;
};