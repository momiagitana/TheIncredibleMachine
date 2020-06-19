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
		kongtext
	};

	enum class Sound
	{
		background,
		menu
	};

	//make the static event so we wont load the textures multiple times
	static ResourceManager& instance();
	sf::Texture* getTexture(GameObject_t name);
	sf::Font& getFont(Font name);
	sf::SoundBuffer& getSound(Sound name);
	std::string& getLevelPath();

private:

	ResourceManager(); //private ctor for singleton
	void loadTexture(std::string path, GameObject_t name);
	void loadFont(std::string path, Font name);
	void loadSound(std::string path, Sound name);

	std::unordered_map<GameObject_t, sf::Texture> m_textures;
	std::unordered_map<Font, sf::Font> m_fonts;
	std::unordered_map<Sound, sf::SoundBuffer> m_sounds;
	std::string m_path;
};