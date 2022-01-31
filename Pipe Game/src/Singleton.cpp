#include "Singleton.h"
#include <iostream>

std::vector<sf::Texture> Singleton::m_textures;
std::vector<sf::Texture*> Singleton::m_tempTexCpy;
std::multimap <int, std::vector<int>  > multimapHalfCircal;
std::multimap <int, std::vector<int>  > multimapLaidDown;
std::multimap <int, std::vector<int>  > multimapTriple;
std::multimap <int, std::vector<int>  > multimapTap;
std::vector<sf::Font> Singleton::m_fonts;
std::vector<sf::Font*> Singleton::m_tempFontCpy;


Singleton& Singleton::getInstance()
{
	static Singleton instance;
	return instance;
}

sf::Texture* Singleton::getTexture(const int& index) const
{
	sf::Texture* p2Texture = new sf::Texture(m_textures[index]);
	m_tempTexCpy.push_back(p2Texture);

	return p2Texture;
}

std::vector <int> Singleton::getNweDirction(const int& map, const int& indexDirction) const
{
	switch (map)
	{
	case 0:
	{
		
		return multimapTap.find(indexDirction)->second;
	}
	case 2:
	{
		
		return multimapLaidDown.find(indexDirction)->second;
	}
	case 3:
	{
		return multimapHalfCircal.find(indexDirction)->second;
	}
	case 4:
	{
		return multimapTriple.find(indexDirction)->second;
	}
	case 5:
		return std::vector <int> {1, 1, 1, 1};
	}
}

sf::Font* Singleton::getFont() const
{
	sf::Font* p2Font = new sf::Font(m_fonts[0]);
	m_tempFontCpy.push_back(p2Font);

	return p2Font;

}

Singleton::~Singleton()
{
	for (auto i = 0; i < m_tempTexCpy.size(); i++)
		delete m_tempTexCpy[i];

	for (auto i = 0; i < m_tempFontCpy.size(); i++)
		delete m_tempFontCpy[i];

	multimapLaidDown.clear();
	multimapHalfCircal.clear();
	multimapTriple.clear();
	multimapTap.clear();
}

Singleton::Singleton() {

	m_textures.resize(13);

	if (!(m_textures[0].loadFromFile("tap.png") &&
		m_textures[1].loadFromFile("sink.png") &&

		m_textures[2].loadFromFile("pipeGrey_01.png") &&
		m_textures[3].loadFromFile("pipeGrey_02.png") &&
		m_textures[4].loadFromFile("pipeGrey_03.png") &&
		m_textures[5].loadFromFile("pipeGrey_04.png") &&

		m_textures[6].loadFromFile("pipeGrey_05.png") &&
		m_textures[7].loadFromFile("pipeGrey_06.png") &&
		m_textures[8].loadFromFile("pipeGrey_07.png") &&
		m_textures[9].loadFromFile("pipeGrey_08.png") &&
		m_textures[10].loadFromFile("back ground.png") &&
		m_textures[11].loadFromFile("level complete.png") &&
		m_textures[12].loadFromFile("win.png")))
		throw std::exception("error in load texture");

	multimapLaidDown.insert(std::make_pair(0, std::vector <int> { 0, 1, 0, 1 }));
	multimapLaidDown.insert(std::make_pair(1, std::vector <int> { 1, 0, 1, 0 }));
	multimapLaidDown.insert(std::make_pair(2, std::vector <int> { 0, 1, 0, 1 }));
	multimapLaidDown.insert(std::make_pair(3, std::vector <int> { 1, 0, 1, 0 }));

	multimapHalfCircal.insert(std::make_pair(0, std::vector <int> { 1, 0, 0, 1 }));
	multimapHalfCircal.insert(std::make_pair(1, std::vector <int> { 1, 1, 0, 0 }));
	multimapHalfCircal.insert(std::make_pair(2, std::vector <int> { 0, 1, 1, 0 }));
	multimapHalfCircal.insert(std::make_pair(3, std::vector <int> { 0, 0, 1, 1 }));

	multimapTriple.insert(std::make_pair(0, std::vector <int> { 1, 0, 1, 1 }));
	multimapTriple.insert(std::make_pair(1, std::vector <int> { 1, 1, 0, 1 }));
	multimapTriple.insert(std::make_pair(2, std::vector <int> { 1, 1, 1, 0 }));
	multimapTriple.insert(std::make_pair(3, std::vector <int> {0, 1, 1, 1 }));

	multimapTap.insert(std::make_pair(0, std::vector <int> { 0, 0, 0, 1 }));
	multimapTap.insert(std::make_pair(1, std::vector <int> { 1, 0, 0, 0 }));
	multimapTap.insert(std::make_pair(2, std::vector <int> { 0, 1, 0, 0 }));
	multimapTap.insert(std::make_pair(3, std::vector <int> { 0, 0, 1, 0 }));
	
	m_fonts.resize(1);
	if (!(m_fonts[0].loadFromFile("font.ttf")))
		throw std::exception("error in load font");


}