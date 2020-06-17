#include "ResourceManager.h"
#include <string>

//makes an instance and is created only once
ResourceManager& ResourceManager::instance()
{
	static ResourceManager instance;
	return instance;
}


sf::Texture* ResourceManager::getTexture(GameObject_t name)
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
	  loadTexture("balloonPopping.png", GameObject_t::balloon);
	  loadTexture("basketBall.png", GameObject_t::basketBall);
	  loadTexture("baseBall.png", GameObject_t::baseBall);
	  loadTexture("bowlingBall.png", GameObject_t::bowlingBall);
	  loadTexture("conveyor.png", GameObject_t::conveyor);
	  loadTexture("bricks.png", GameObject_t::brickWallH);
	  loadTexture("bricksV.png", GameObject_t::brickWallV);
	  loadTexture("worker.jpg", GameObject_t::play);
	  loadTexture("arrows.png", GameObject_t::arrows);
	  loadTexture("startButton.png", GameObject_t::start_button);
	  loadTexture("exitButton.png", GameObject_t::exit_button);
	  loadTexture("The_Incredible_Machine.png", GameObject_t::background);

	//loadTexture("build/balloonPopping.png", GameObject_t::balloon);
	//loadTexture("build/basketBall.png", GameObject_t::basketBall);
	//loadTexture("build/baseBall.png", GameObject_t::baseBall);
	//loadTexture("build/bowlingBall.png", GameObject_t::bowlingBall);
	//loadTexture("build/conveyor.png", GameObject_t::conveyor);
	//loadTexture("build/bricks.png", GameObject_t::brickWallH);
	//loadTexture("build/bricksV.png", GameObject_t::brickWallV);
	//loadTexture("build/worker.jpg", GameObject_t::play);
	//loadTexture("build/arrows.png", GameObject_t::arrows);

	//

	//---------- font ---win-------
	loadFont("C:/Windows/Fonts/Arial.ttf", Font::ariel);

	//---------- font ----------
	//loadFont("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/Amadeus.ttf", Font::ariel);
	

	//---------- sound ----------
	 loadSound("menu.ogg", Sound::menu);
	 loadSound("background.ogg", Sound::background);

	//loadSound("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/menu.ogg", Sound::menu);
	//loadSound("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/background.ogg", Sound::background);

}

void ResourceManager::loadTexture(std::string path, GameObject_t name)
{
	sf::Texture temp;
	temp.loadFromFile(path);
	m_textures[name] = temp; // why cant it be m_textures[name].loadFromFile(path);

	
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

