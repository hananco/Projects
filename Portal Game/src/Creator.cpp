#include "Creator.h"
std::shared_ptr<GameObject> Creator::create(const char& name, const sf::Vector2f& loc, const sf::Vector2f& objSize,b2World& world) {
	auto it = Creator::getMap().find(name);
	if (it == Creator::getMap().end())
		return nullptr;
	return it->second(name, loc, objSize, world);
}
bool Creator::registerit(const char& name, pFnc f) {
	Creator::getMap().emplace(name, f);
	return true;
}