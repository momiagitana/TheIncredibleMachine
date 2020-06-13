#include "ResourceManager.h"
#include <string>

//makes an instance and is created only once
ResourceManager& ResourceManager::instance()
{
	static ResourceManager instance;
	return instance;
}


sf::Texture* ResourceManager::getTexture(Texture name)
{
	return &(m_textures[name]);
}


sf::Font& ResourceManager::getFont(Font name)
{
	return m_fonts[name];
}


sf::SoundBuffer& ResourceManager::getSound(Sound name)
{
	return m_sounds[name];
}


//CTOR
ResourceManager::ResourceManager()
{
	//---------- textures -------windows---
	// loadTexture("balloonPopping.png", Texture::balloonPopping);
	// loadTexture("basketBall.png", Texture::basketBall);
	// loadTexture("baseBall.png", Texture::baseBall);
	// loadTexture("bowlingBall.png", Texture::bowlingBall);
	// loadTexture("conveyor.png", Texture::conveyor);
	// loadTexture("flooringHorizontal.png", Texture::flooringHorizontal);
	// loadTexture("flooringVertical.png", Texture::flooringVertical);
	

	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/balloonPopping.png", Texture::balloonPopping);
	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/basketBall.png", Texture::basketBall);
	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/baseBall.png", Texture::baseBall);
	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/bowlingBall.png", Texture::bowlingBall);
	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/conveyor.png", Texture::conveyor);
	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/flooringHorizontal.png", Texture::flooringHorizontal);
	loadTexture("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/flooringVertical.png", Texture::flooringVertical);
	

	//---------- font ---win-------
	//loadFont("C:/Windows/Fonts/Arial.ttf", Font::ariel);

	//---------- font ----------
	loadFont("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/Amadeus.ttf", Font::ariel);
	

	//---------- sound ----------
	// loadSound("menu.ogg", Sound::menu);
	// loadSound("background.ogg", Sound::background);

	loadSound("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/menu.ogg", Sound::menu);
	loadSound("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/background.ogg", Sound::background);

}

void ResourceManager::loadTexture(std::string path, Texture name)
{
	sf::Texture temp;
	temp.loadFromFile(path);
	m_textures[name] = temp;
}

void ResourceManager::loadFont(std::string path, Font name)
{
	sf::Font temp;
	temp.loadFromFile(path);
	m_fonts[name] = temp;
}

void ResourceManager::loadSound(std::string path, Sound name)
{
	sf::SoundBuffer temp;
	temp.loadFromFile(path);
	m_sounds[name] = temp;
}

