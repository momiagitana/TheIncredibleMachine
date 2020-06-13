/*
this is a singleton static class for holding the textures,sounds and fonts and
makes sure they wont be loaded more then once
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class ResourceManager
{
public:
	enum class Texture 
	{
		balloonPopping,
		basketBall,
		baseBall,
		bowlingBall,
		conveyor,
		flooringHorizontal,
		flooringVertical
	};

	enum class Font
	{
		ariel
	};

	enum class Sound
	{
		background,
		menu
	};

	//make the static event so we wont load the textures multiple times
	static ResourceManager& instance();
	sf::Texture* getTexture(Texture name);
	sf::Font& getFont(Font name);
	sf::SoundBuffer& getSound(Sound name);
	void run(); ///test

private:
	
	ResourceManager(); //private ctor for singleton
	void loadTexture(std::string path, Texture name);
	void loadFont(std::string path, Font name);
	void loadSound(std::string path, Sound name);

	std::unordered_map<Texture, sf::Texture> m_textures;
	std::unordered_map<Font, sf::Font> m_fonts;
	std::unordered_map<Sound, sf::SoundBuffer> m_sounds;
};

