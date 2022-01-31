#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <map>
class Singleton 
{
public:
	static Singleton& getInstance();
	sf::Texture* getTexture(const int&) const;//return the texture
	// a multimap thet have the all dirction for ech pipe in ech angle
	std::vector <int> getNweDirction(const int& map , const int& indexDirction) const;
	sf::Font* getFont() const;// the front for text

	~Singleton();

private:
	Singleton();
	static std::vector<sf::Font> m_fonts;
	static std::vector<sf::Font*> m_tempFontCpy;	
	static std::vector<sf::Texture> m_textures;
	static std::vector<sf::Texture*> m_tempTexCpy;	
	std::multimap <int, std::vector<int>  > multimapHalfCircal;// a multi map for dirction of Half Circal pipe
	std::multimap <int, std::vector<int>  > multimapLaidDown;// a multi map for dirction of Laid Down pipe
	std::multimap <int, std::vector<int>  > multimapTriple;//// a multi map for dirction of Triple pipe
	std::multimap <int, std::vector<int>  > multimapTap;// a multimap for dirction of a tap 
	

	

};