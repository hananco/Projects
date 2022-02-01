#include "Animation.h"
#include <iostream>

//================================CONSTRACTOR==================================
Animation::Animation(const sf::Vector2f& objsize ,const vector <string> &names1 , 
	const vector <string>& names2)
{
	Resources& p2Sin = Resources::getInstance();
	for (auto& dir : m_direction) dir.first = 0;
	load(p2Sin.getAnimationLeftTexture(), m_move[LEFT] , objsize);
	load(p2Sin.getAnimationRightTexture(), m_move[RIGHT] , objsize);
}
//===================================MOVE======================================
//Return the sprite of the animation
//=============================================================================
sf::Sprite Animation::move(const int& direction) {

	//reset the other direction data
	for (int i = 0; i < m_direction.size(); i++ ) {
		if (i != direction)
		{
			m_direction[i].first = 0; 
			m_direction[i].second.restart();
		}
	}

	if (m_direction[direction].second.getElapsedTime().asSeconds() > 0.1f)
	{
		m_direction[direction].first++;
		m_direction[direction].first = m_direction[direction].first % m_move[direction].size();
		m_direction[direction].second.restart();
	}
	return m_move[direction][m_direction[direction].first];
}
//==================================LOAD=======================================
//Set the textures and sprites
//=============================================================================
void Animation::load(vector<sf::Texture> &texVec, vector <sf::Sprite> &spVec ,
	 const sf::Vector2f& objsize){

	for (int i = 0; i < texVec.size(); i++)
	{
		spVec.push_back(sf::Sprite());
		spVec[i].setTexture(texVec[i]);
		spVec[i].setOrigin(spVec[i].getGlobalBounds().width / 2, spVec[i].getGlobalBounds().height / 2);
		spVec[i].setScale(objsize.x / spVec[i].getLocalBounds().width,
			objsize.y / spVec[i].getLocalBounds().height);
	}
}