#pragma once
#include "Resources.h"
using namespace std;

/* CLASS ANIMATION :
* ============================================================================
* This class is responsible for the objects animation
*/

class Animation
{
public:
	Animation(const sf::Vector2f& objsize , const vector <string>& names1,
		const vector <string>& names2);
	sf::Sprite move(const int &direction);
	void load(vector<sf::Texture> &texVec, vector <sf::Sprite> &spVec ,
		 const sf::Vector2f& objsize);
private:
	vector <vector <sf::Sprite>> m_move{vector <sf::Sprite>() , vector <sf::Sprite>()};
	vector<pair <int, sf::Clock>> m_direction{ pair <int , sf::Clock>(), pair <int, sf::Clock>()};
};
