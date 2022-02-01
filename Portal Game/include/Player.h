#pragma once
#include "UnFixedObject.h"
#include "Animation.h"
#include "Elevator.h"
#include "Wall.h"
#include <math.h>
class Box ; 
class Acid;
class Elevator ;
class Button;
class Trampoline ;
class TimePresent;
class ButtonFloor;
class BadLaser;

class Player :public UnFixedObject
{
public:
    using UnFixedObject::UnFixedObject;
    Player(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world);
    void move(const int& key , sf::Time deltaTime);
    void draw(sf::RenderWindow&) override;
    void rotateToMouse(sf::RenderWindow& window);
    void box(b2Body& box);
    bool isExtraTime();
    bool getRestart() const;
    bool returnIsLevelEnd() const { return m_levelEnd;}
    bool getBox();
    void resetBody() override;
    float updateMove(const int &movement , float time);
    bool getIfLevelCompleted() const ;

    void handleCollision(GameObject& gameObject) override;
    void handleCollision(Elevator& gameObject) override ;
    void handleCollision(Acid& gameObject) override;
    void handleCollision(TimePresent& gameObject) override;
    void handleCollision(Wall& gameObject) override;
    void handleCollision(BadLaser& gameObject) override;
    void handleCollision(Player& gameObject) override {/*ignore*/ };
    void handleCollision(Box& gameObject) override {/*ignore*/ };
    void handleCollision(Button& gameObject) override {/*ignore*/};
    void handleCollision(Trampoline& gameObject) override {/*ignore*/};
    void handleCollision(ButtonFloor& gameObject) override {/*ignore*/}

private:
    void updateGunSprite(const sf::Vector2f& objSize, const sf::Vector2f& loc, Resources& p2Sin);
    void updateAnimatedMove(bool& first, bool& second, const int& direction);
    Animation m_animation;
    sf::Sprite m_gunSprite;
    b2Body* m_box = nullptr;
    b2Joint* joint;
    b2WeldJointDef wj;

    const double PI = 3.14159265;
    bool m_firstR = true, m_firstL = true,
        m_restart = false, m_onGround = true , m_extraTime = false;
    static bool m_registerit;
};