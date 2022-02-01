#include "Resources.h"
//==============================CONSTRUCTOR====================================
Resources::Resources()
{
	setData(IMAGES_NAMES, m_textures);
	setData(FONTS_NAMES, m_fonts);
	setData(SOUNDS_NAMES, m_soundBuffers);
	setData(PLATER_RIGHT_PIC_NAMES, m_RightPlayerAnimationTextures);
	setData(PLATER_LEFT_PIC_NAMES, m_leftPlayerAnimationTextures);
	setMusic();
}
//=============================GET INSTANCE====================================
//RETURN OBJECT OF THIS CLASS
//=============================================================================
Resources& Resources::getInstance()
{
	static Resources instance;
	return instance;
}
//==============================GET TEXTURE====================================
//RETURN WANTED TEXTURE
//=============================================================================
sf::Texture& Resources::getTexture(const int& index)
{
	return m_textures[index];
}
//=====================GET ANIMATION LEFT TEXTURE==============================
//RETURN WANTED TEXTURE FOR THE ANIMATION USE
//=============================================================================
std::vector <sf::Texture>&  Resources::getAnimationLeftTexture() {
	return m_leftPlayerAnimationTextures;
}
//=====================GET ANIMATION RIGHT TEXTURE=============================
//RETURN WANTED TEXTURE FOR THE ANIMATION USE
//=============================================================================
std::vector <sf::Texture>&  Resources::getAnimationRightTexture() {
	return m_RightPlayerAnimationTextures;
}
//==============================GET FONT=======================================
//RETURN WANTED FONT
//=============================================================================
sf::Font& Resources::getFont()
{
	return m_fonts[0];
}
//===========================GET SOUND BUFFER==================================
//RETURN WANTED SOUND BUFFER
//=============================================================================
sf::SoundBuffer& Resources::getSoundBuffer(const int& index)
{
	return m_soundBuffers[index];
}
//=============================PLAY MUSIC======================================
//THIS FUNCTION IS BEEN CALLED WHEN WE HAVE THE GAME MAIN MUSIC, FIRST ELEMENT
//IN PAIR IS FOR THE MAIN MUSIC AND THE SECOND ONE IS FOR THE EVENTS MUSIC,
//WHEN EVENT MUSIC WANT TO BE PLAYED THE MAIN MUSIC STOP AND WHEN THE EVENT 
//MUSIC FINISHED THE MAIN MUSIC CONTINUE
//=============================================================================
void Resources :: playMusic(const int& index, const bool& loop)
{
	if (index == GAME_SOUND && m_music.first->getStatus() != sf::Sound::Playing) {
		if (m_music.second == nullptr || m_music.second->getStatus() != sf::Sound::Playing) {
			m_music.first->play();
			m_music.first->setLoop(loop);
		}
	}
	else if (index != GAME_SOUND)
	{
		m_music.first->pause();
		m_music.second = &m_sounds[index];
		m_music.second->play();
		m_music.second->setLoop(loop);
	}
}
//==========================PLAY MUSIC REGULAR=================================
//THIS FUNCTION IS BEEN CALLED WHEN WE DONT HAVE THE GAME MAIN MUSIC,
//WANTED MUSIC WILL BE PLAYED
//=============================================================================
void Resources::playMusicRegular(const int& index, const bool& loop) {
	m_sounds[index].play();
	m_sounds[index].setLoop(loop);
}
//===============================SET MUSIC=====================================
//SET THE MUSIC
//=============================================================================
void Resources::setMusic() {

	m_sounds.resize(m_soundBuffers.size());
	for (int i = 0 ; i < m_soundBuffers.size(); i++)
	{
		m_sounds[i].setBuffer(m_soundBuffers[i]);
		m_sounds[i].setVolume(MUSIC_VOLUME);
	}
	m_music.first = &m_sounds[GAME_SOUND];
	m_music.second = nullptr;
}
//================================STOP=========================================
//STOP THE WANTER MUSIC
//=============================================================================
void Resources::stop(const int& index) {
	m_sounds[index].stop();
}