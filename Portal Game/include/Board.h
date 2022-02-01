#pragma once
#include "Player.h"
#include "Acid.h"
#include "Box.h"
#include "Button.h"
#include "Elevator.h"
#include "TimePresent.h"
#include "Trampoline.h"
#include "Wall.h"
#include "Resources.h"
#include "ButtonFloor.h"
#include "BadLaser.h" 
#include "File.h"
#include "Fence.h"
#include "Creator.h"

class Board
{
public:
	Board();
	bool end();
	void restart(b2World& world);
	void operator++();
	void begin(b2World& world);
	void draw(sf::RenderWindow& window);
	void createObject(const char& type, const sf::Vector2f& loc, const sf::Vector2f& objSize, b2World& world);
	void createMap(b2World& world);
	void handleCollisions();
	void handlePress(sf::RenderWindow& window , const bool &type , b2World& world);
	void fire();
	int getTime() const;
	void movePlayer(const int& key, sf::Time deltaTime);
	void roratePlayerGun(sf::RenderWindow& window);
	bool getnextLevel() const; 
	bool getTimePresent() const;
	bool getRestart () const;
	void initCurrentLevel();
	int getLevel();
	
private:
	template <typename T> void clearWorld(std::vector <std::shared_ptr<T>> objects , b2World& world) {
		if (world.GetBodyCount() > 0)
			for (auto& obj : objects)
				world.DestroyBody(obj->getBody());
	}
	bool path(b2Body* obj1, b2Body* obj2, b2World& world);
	std::vector<std::shared_ptr<ButtonFloor>> m_data;
	std::vector<std::shared_ptr<GameObject>> m_objects;
	std::shared_ptr<Player> m_player;
	std::vector<shared_ptr<GameObject>> m_portal = { nullptr , nullptr };
	int m_currentLevel = 1;
	sf::Sprite m_backGround;
	sf::Clock m_fireClock;
	File m_file;
	RayCastCallback m_callback;
};