#pragma once
#include "FixedObject.h"
#include "Bullet.h"
#include "RayCastCallBack.h"
class Player;
class Wall;
class Player;
class Box;
class Acid;
class Elevator;
class Button;
class Trampoline;
class TimePresent;
class ButtonFloor;

class BadLaser : public FixedObject
{
public:
    BadLaser(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world);
    void fire();
    void draw(sf::RenderWindow&);
    bool collision(const b2Body*) override;
    bool doesFire();
    void port(const b2Vec2& pos) override;
    void resetBody() override;
    void notPort() override;
    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Player& gameObject) override {/*ignore*/ }
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
    void handleCollision(Box& gameObject) override {/*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(ButtonFloor& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handleCollision(BadLaser& gameObject) override {/*ignore*/ }


private:
    std::vector<Bullet> m_bullets;
    sf::Vector2f m_shotDirection, m_portLoc, m_portDir;
    RayCastCallback m_callBack;
    sf::Clock m_clock, m_totalTime;
    bool m_inPortal = false;
    static bool m_registerit;
};