#pragma once/*
#include "Player.h"
#include "Acid.h"
#include "Box.h"
#include "Button.h"
#include "Elevator.h"
#include "TimePresent.h"
#include "Trampoline.h"
#include "Wall.h"
#include "ButtonFloor.h"
#include "BadLaser.h" 
#include "Fence.h"
#include <unordered_map>
#include <vector>
#include "Resources.h"
*/
#include "GameObject.h"
#include <map>
#include <string>

class Creator
{
public:
	using pFnc = std::shared_ptr <GameObject>(*)(const char& , const sf::Vector2f& , const sf::Vector2f& , b2World& );
	static std::shared_ptr<GameObject> create(const char& name ,const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world);
	static bool registerit(const char& name, pFnc);
private:
	static auto& getMap() {
		static std::map<char, pFnc> map;
		return map;
	}
};