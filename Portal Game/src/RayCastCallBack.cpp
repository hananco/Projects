#include "RayCastCallBack.h"
//=============================REPORT FIXTURE==================================
//THIS FUNCTION IS OVERRIDE OF THE BOX2D B2RAYCASTCALLBACK REPORT FIXTURE 
//FUNCTION AND IT IS ADJUSTED FOR OUR PROGRAM NEEDS
//=============================================================================
float RayCastCallback :: ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction)
{
	if (fixture->GetBody() != m_start && fixture->GetBody() != m_end && fraction < 0.9f) {
		line.pop_back();
		line.push_back(sf::Vertex(sf::Vector2f(fixture->GetBody()->GetPosition().x, fixture->GetBody()->GetPosition().y)));
		m_path = false;
		m_coliision = fixture->GetBody();
		return 0;
	}
	return 1;
}
//==================================SET========================================
//RESET THE PATH , COLLISON AND LINE MEMBER, LOAD THE START AND END OBJECTS
//AND SET THE LINE
//=============================================================================
void RayCastCallback :: set(b2Body* a, b2Body* b)
{
	m_path = true;
	b2Body* coliision = nullptr;
	line.clear();
	m_start = a;
	m_end = b;
	line.push_back(sf::Vertex(sf::Vector2f(m_start->GetPosition().x, m_start->GetPosition().y)));
	line.push_back(sf::Vertex(sf::Vector2f(m_end->GetPosition().x, m_end->GetPosition().y)));
}
//==================================PATH=======================================
//RETURN IF THERE IS A PATH BETWEEN THE 2 LOCATIONS
//=============================================================================
bool RayCastCallback :: path() { 
	return m_path; 
}
//===========================GET COLLISION=====================================
//RETURN THE FIRST ELEMENT THAT WAS IN THE WANTED PATH
//=============================================================================
b2Body* RayCastCallback::getcoliision() {
	return m_coliision;
}