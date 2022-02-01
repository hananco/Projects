#include "DataBar.h"
//==============================CONSTRUCTOR====================================
DataBar::DataBar() : m_toolBar(sf::Vector2f((float)WINDOW_WIDTH, (float)DATA_BAR_HEIGHT)) {

	Resources& p2Sin = Resources::getInstance();
	m_toolBar.setPosition({ 0, WINDOW_HEIGHT - DATA_BAR_HEIGHT});
	m_toolBar.setFillColor(sf::Color::Black);
	m_toolBar.setOutlineColor(sf::Color::Black);
	m_toolBar.setOutlineThickness(3);
	m_texts.resize(DATA_BAR_STRING.size());
	m_strings.resize(DATA_BAR_STRING.size());

	for (auto i = 0; i < m_texts.size(); i++) {
		m_texts[i].setFont(p2Sin.getFont());
		m_texts[i].setPosition(sf::Vector2f(WINDOW_WIDTH/2.5*i + DATA_WIDTH, (float)(WINDOW_HEIGHT)-(float)(DATA_BAR_HEIGHT) * 0.75));
		m_texts[i].setCharacterSize(NORAML_BUTTON_SIZE);
		m_texts[i].setFillColor(sf::Color::White);
	}
}
void DataBar::Draw(sf::RenderWindow& window, const int& level, const int& time, const bool& difficulty) {

	Resources& p2Sin = Resources::getInstance();
	window.draw(m_toolBar);
	m_strings[FIRST_DATA] = DATA_BAR_STRING[FIRST_DATA] + std::to_string(level);
	m_strings[SECOND_DATA] = DATA_BAR_STRING[SECOND_DATA];

	if (time == TIME_LIMIT && difficulty)
		p2Sin.playMusic(TIMER_SOUND, false);

	// Difficulty = Hard
	if (difficulty) {
		if (time < TIME_LIMIT && time > 0) {
			m_texts[SECOND_DATA].setCharacterSize(BIG_BUTTON_SIZE);
			m_texts[SECOND_DATA].setFillColor(sf::Color::Red);
		}
		else if (time > TIME_LIMIT) {
			m_texts[SECOND_DATA].setCharacterSize(NORAML_BUTTON_SIZE);
			m_texts[SECOND_DATA].setFillColor(sf::Color::White);
		}
		m_strings[SECOND_DATA].append(std::to_string(time));
	}
	else {	// Difficulty = Easy
		m_texts[SECOND_DATA].setCharacterSize(NORAML_BUTTON_SIZE);
		m_strings[SECOND_DATA].append("Infinity");	// Infinity time
	}

	for (auto i = 0; i < m_texts.size(); i++) {
		m_texts[i].setString(m_strings[i]);
		window.draw(m_texts[i]);
	}
}