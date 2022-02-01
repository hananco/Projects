#pragma once
#include "MenuButton.h"
#include "Explenation.h"
#include <iostream>

/* CLASS MENU :
* ============================================================================
* This class is responsible for the start menu of the game 
*/

class Menu 
{
public:
	Menu();
	void runMenu(sf::RenderWindow& window);
	void checkReleased(sf::RenderWindow& window);
	void checkMousOn(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	bool getDifficulty() const;
	void setDifficulty();

private:
	void music();
	void startWindow();
	void startMusic();
	void draw(sf::RenderWindow& window ,std::vector<MenuButton>& vecButton);
	void setBackGround();
	bool checkDifficulty(sf::RenderWindow& window);

	std::vector <sf::Texture> m_texture;
	std::vector<MenuButton> m_buttonsMenu;
	std::vector<MenuButton> m_DifficultyButtons;
	sf::Music m_music;
	sf::Sprite m_sprite;
	bool m_musicIsOn = true;
	bool m_onDifficulty = false;
	static bool  m_difficulty;
	Explenation m_explenation;
};