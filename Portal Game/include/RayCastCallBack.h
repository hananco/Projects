#pragma once
#include "box2d/box2d.h"
#include <SFML/Graphics.hpp>
#include <vector>

class RayCastCallback : public b2RayCastCallback
{
public:
	std :: vector <sf::Vertex> line = { sf::Vertex() , sf::Vertex() };
	void set(b2Body* a, b2Body* b);
	RayCastCallback() {};
	virtual float ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction) override;
	bool path();
	b2Body* getcoliision();
	template <typename T> bool rayCastValid(const T& loc1, const T& loc2) {
		return(sqrt(pow(float(loc1.x - loc2.x), 2) + (pow(float(loc1.y - loc2.y), 2))) > 0.f);
	}
private:
	b2Body* m_start = nullptr;
	b2Body* m_end = nullptr;
	b2Body* m_coliision = nullptr;
	bool m_path = true;
};
