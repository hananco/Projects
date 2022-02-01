#pragma once
#include "ButtonFloor.h"
class Player;
class Wall;
class Player;
class Box;
class Acid;
class Elevator;
class Trampoline;
class TimePresent;
class BadLaser;

class Button :public FixedObject
{
public:
    //Resources& p2Sin = Resources::getInstance();
    Button(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world);
    void addElement(std::vector<std::shared_ptr<ButtonFloor>>obj) override;
    void handleCollision(GameObject& gameObject) override;
    void draw(sf::RenderWindow& window) override;
    void handleCollision(Player& gameObject) override {/*ignore*/ }
    void handleCollision(Wall& gameObject) override {/*ignore*/ }
    void handleCollision(Box& gameObject) override { /*ignore*/ }
    void handleCollision(Acid& gameObject) override {/*ignore*/ }
    void handleCollision(Elevator& gameObject) override {/*ignore*/ }
    void handleCollision(Button& gameObject) override {/*ignore*/ }
    void handleCollision(Trampoline& gameObject) override {/*ignore*/ }
    void handleCollision(TimePresent& gameObject) override {/*ignore*/ }
    void handleCollision(ButtonFloor& gameObject) override {/*ignore*/ }
    void handleCollision(BadLaser& gameObject) override {/*ignore*/ }

private:
    std::vector< std::shared_ptr <ButtonFloor>> m_elements;
    static bool m_registerit;
};