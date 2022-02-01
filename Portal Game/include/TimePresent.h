#pragma once
#include "FixedObject.h"
#include <Player.h>
//class Player;
class ButtonFloor;
class Wall;
class Box;
class Acid;
class Elevator;
class Trampoline;
class Button;
class BadLaser;

class TimePresent :public FixedObject
{
public:
    TimePresent(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world);
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Player& gameObject) override {};
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