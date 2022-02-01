#pragma once
#include <iostream>
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Resources.h"
#include <memory>
#include <vector>

class Player;
class Wall;
class Box ; 
class Acid;
class Elevator ;
class Button;
class Trampoline ;
class TimePresent;
class ButtonFloor;
class BadLaser;
class Singelton;


class GameObject{
public:
  
    GameObject(const char& index, const sf::Vector2f& loc, const sf::Vector2f& objSize, const sf::Texture& texture, b2World& world , const bool &dynamic);
    virtual ~GameObject() = default;
    GameObject() = default;
    virtual void addElement(std::vector<std::shared_ptr<ButtonFloor>>) {};
    bool checkCollision(sf::FloatRect rec) const;
    virtual void handlePress(Player& gameObject) {};
    virtual void NotPressed() {};
    virtual void port(const b2Vec2 &pos) {};
    virtual bool Press(const bool& enter) ;
    bool isDisposed() const;
    sf::FloatRect getGlobalBounds() const;
    virtual void draw(sf::RenderWindow&);
    void setAble(bool b);
    virtual void jump() {}
    b2Vec2 getPosition();
    b2Body* getBody() const;
    void ifOutOfRange();
    virtual void resetBody();
    void upElevator();
    virtual void notPort() {};
    void play(const int& index, const bool& loop);

    virtual bool collision(const b2Body*);
    virtual void handleCollision(GameObject&) = 0;
    virtual void handleCollision(Player&) = 0;
    virtual void handleCollision(Wall&) = 0;
    virtual void handleCollision(Box&) = 0;
    virtual void handleCollision(Acid&) = 0;
    virtual void handleCollision(Elevator&) = 0;
    virtual void handleCollision(Button&) = 0;
    virtual void handleCollision(Trampoline&) = 0;
    virtual void handleCollision(TimePresent&) = 0;
    virtual void handleCollision(ButtonFloor& ) = 0;
    virtual void handleCollision(BadLaser&) = 0;
  
protected:
    bool m_isDisposed = false;
    sf::Sprite m_sprite;  
    b2Body* m_body = nullptr;
    b2World* m_world;
    bool m_levelEnd = false;
    bool m_finish = false;


private:
    sf::Vector2f m_startLoc;
    void updateSprite(const sf::Vector2f&, const sf::Vector2f& objSize);
    void setWorldBody(const bool&);
};