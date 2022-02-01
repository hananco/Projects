#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Const.h"

class Resources
{
public:
	Resources();
	~Resources() = default;
	static Resources& getInstance();
	sf::Texture& getTexture(const int&);
	std::vector<sf::Texture>& getAnimationLeftTexture();
	std::vector <sf::Texture>& getAnimationRightTexture();
	sf::Font& getFont();
	sf::SoundBuffer& getSoundBuffer(const int& index);
	void stop(const int& index);
	void playMusic(const int &index, const bool& loop);
	void playMusicRegular(const int& index , const bool& loop);

private:
	std::vector<sf::Font> m_fonts;
	std::vector<sf::Texture> m_textures, m_leftPlayerAnimationTextures,
		m_RightPlayerAnimationTextures;
	std::vector<sf::SoundBuffer> m_soundBuffers;
	std::vector <sf::Sound> m_sounds;
	std :: pair <sf::Sound*, sf::Sound*> m_music;

	void setMusic();

	template <typename T> void setData(const std::vector <std::string>& names, std::vector<T>& data) {
		data.resize(names.size());
		for (int i = 0; i < data.size(); i++) {
			if (!(data[i].loadFromFile(names[i])))
				throw std::exception("loading Error");
		}
	}
};