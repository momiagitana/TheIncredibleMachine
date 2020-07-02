/*
this is a singleton static class for holding the textures,sounds and fonts and
makes sure they wont be loaded more then once
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include "globals.h"


class ResourceManager
{
public:

	enum class Font
	{
		kongtext,
		CourierNew,
	};

	enum class Sound
	{
		background,
		menu,
		build
	};
	//make the static event so we wont load the textures multiple times
	static ResourceManager& instance();
	sf::Texture* getTexture(const Type_t);
	sf::Font& getFont(const Font);
	std::string& getLevelPath();
	void setSong(const int);
	void volUp();
	void volDown();



private:

	ResourceManager(); //private ctor for singleton
	void loadTexture(const std::string, const Type_t);
	void loadFont(const std::string, const Font);
	void loadSound(const std::string, const Sound);
	sf::SoundBuffer& getSound(const Sound);
	void setSounds();
	void stopAllSongs();
	void playSong();
	void setVolume();


	std::unordered_map<Type_t, sf::Texture> m_textures;
	std::unordered_map<Font, sf::Font> m_fonts;
	std::unordered_map<Sound, sf::SoundBuffer> m_soundBuff;
	std::string m_path;

	std::vector <sf::Sound> m_sounds;
	Sound m_playing;
	int m_volume = 56; //fix medium vol
};