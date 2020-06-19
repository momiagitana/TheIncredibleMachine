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

std::string& ResourceManager::getLevelPath()
{

	return m_path;

	//for mac
}


//CTOR
ResourceManager::ResourceManager()
{
	//---------- textures -------windows---

	//    loadTexture("balloonPopping.png", GameObject_t::balloon);
	//    loadTexture("basketBall.png", GameObject_t::basketBall);
	//    loadTexture("baseBall.png", GameObject_t::baseBall);
	//    loadTexture("bowlingBall.png", GameObject_t::bowlingBall);
	//    loadTexture("conveyor.png", GameObject_t::conveyor);
	//    loadTexture("brickH.png", GameObject_t::brickWallH);
	//    loadTexture("brickV.png", GameObject_t::brickWallV);
	//    loadTexture("play.png", GameObject_t::play);
	//    loadTexture("arrows.png", GameObject_t::arrows);
	//    loadTexture("startButton.png", GameObject_t::start_button);
	//    loadTexture("exitButton.png", GameObject_t::exit_button);
	//    loadTexture("The_Incredible_Machine.png", GameObject_t::background);

	loadTexture("build/balloonPopping.png", GameObject_t::balloon);
	loadTexture("build/basketBall.png", GameObject_t::basketBall);
	loadTexture("build/baseBall.png", GameObject_t::baseBall);
	loadTexture("build/bowlingBall.png", GameObject_t::bowlingBall);
	loadTexture("build/conveyor.png", GameObject_t::conveyor);
	loadTexture("build/bricksH.png", GameObject_t::brickWallH);
	loadTexture("build/brickV.png", GameObject_t::brickWallV);
	loadTexture("build/play.png", GameObject_t::play);
	loadTexture("build/arrows.png", GameObject_t::arrows);
	loadTexture("build/startButton.png", GameObject_t::start_button);
	loadTexture("build/exitButton.png", GameObject_t::exit_button);
	loadTexture("build/The_Incredible_Machine.png", GameObject_t::background);


	//

	//---------- font ---win-------
	// loadFont("kongtext.ttf", Font::kongtext);
	loadFont("build/kongtext.ttf", Font::kongtext);


	//---------- sound ----------
	//  loadSound("menu.ogg", Sound::menu);
	//  loadSound("background.ogg", Sound::background);

	loadSound("build/menu.ogg", Sound::menu);
	loadSound("build/background.ogg", Sound::background);

	//  m_path = "levels.txt";
		m_path = "build/levels.txt";
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

