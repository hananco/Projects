#pragma once
#include "Menu.h"
#include "DataBar.h"
#include "Board.h"
#include <chrono>
#include <thread>

class GameMaster {
public:
	GameMaster();
	void run();
private:
	void drawTryAgain(const sf::Sprite& backGround, MenuButton& btn);
	void setTextTryAgain();
	void endGameHandler( b2World& world);
	bool checkTimer() const;
	void tryAgain();
	void updateMouseSprite();
	void updateTimer();
	void updateScreen();
	void handleExtraTime();
	void playMusic(const float& time, const int& soundIndex);
	void levelCompleted(const int& picIndex , const int& soundIndex);
	void handleKeyPress(const int& key, bool& pressed, sf::Time deltaTime);
	void handleMouseReleased(const sf::Event& event, b2World& world);
	void handleMouseMove();
	void handleFailure(b2World& world, bool& pressed);
	sf::Text m_textTryAgain;
	sf::RenderWindow m_window;
	DataBar m_dataBar;
	Board m_board;
	Menu m_menu;
	sf::Sprite m_mouseSprite;
	sf::Clock m_gameClock, m_deltaClock;
	int m_gameTime, m_totalTime;
};