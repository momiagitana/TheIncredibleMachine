#include "ResourceManager.h"


//makes an instance and is created only once
ResourceManager& ResourceManager::instance()
{
	static ResourceManager instance;
	return instance;
}


sf::Texture* ResourceManager::getTexture(Type_t name)
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
}
                                 

//CTOR
ResourceManager::ResourceManager()
{
	//---------- textures -------windows---

    loadTexture("balloon.png", Type_t::balloon);
    loadTexture("basketBall.png", Type_t::basketBall);
    loadTexture("baseBall.png", Type_t::baseBall);
    loadTexture("bowlingBall.png", Type_t::bowlingBall);
    loadTexture("conveyor.png", Type_t::conveyor);
    loadTexture("brick.png", Type_t::brickWall);
    loadTexture("balloonButton.png", Type_t::balloonButton);
    loadTexture("mouseEngine.png", Type_t::mouseEngine);


    loadTexture("basketButton.png", Type_t::basketButton);
    loadTexture("baseButton.png", Type_t::baseButton);
    loadTexture("bowlingButton.png", Type_t::bowlingButton);
    loadTexture("conveyorButton.png", Type_t::conveyorButton);
    loadTexture("brickButton.png", Type_t::brickWallButton);
    loadTexture("resizeButton.png", Type_t::resizeButton);
    loadTexture("rotateButton.png", Type_t::rotateButton);
    loadTexture("mouseEngineButton.png", Type_t::mouseEngineButton);
    loadTexture("beltButton.png", Type_t::beltButton);

    loadTexture("engineConectButton.png", Type_t::connectButton);

    loadTexture("arrowLButton.png", Type_t::arrowLButton);
    loadTexture("arrowRButton.png", Type_t::arrowRButton);
	loadTexture("chooseLevelButton.png", Type_t::choseLevel);


    loadTexture("advanceButton.png", Type_t::advanceButton);
    loadTexture("puzzleComplete.png", Type_t::puzzleComplete);
    loadTexture("replayButton.png", Type_t::replayButton);

    loadTexture("play.png", Type_t::play);
    loadTexture("exit.png", Type_t::exitButton);
    loadTexture("playmenu.png", Type_t::startButton);
    loadTexture("bomb.png", Type_t::reset);
    loadTexture("sound.png", Type_t::sound);

    loadTexture("menuBackground.png", Type_t::menuBackground);
    loadTexture("frame.png", Type_t::frame);

	loadTexture("choseLevelMenu.png", Type_t::choseLevelMenu);
	loadTexture("playButton.png", Type_t::playButton);
	loadTexture("upButton.png", Type_t::upButton);
	loadTexture("downButton.png", Type_t::downButton);


	////textures for mac----------
	/*loadTexture("build/balloon.png", Type_t::balloon);
	loadTexture("build/basketBall.png", Type_t::basketBall);
	loadTexture("build/baseBall.png", Type_t::baseBall);
	loadTexture("build/bowlingBall.png", Type_t::bowlingBall);
	loadTexture("build/conveyor.png", Type_t::conveyor);
	loadTexture("build/brick.png", Type_t::brickWall);
	loadTexture("build/balloonButton.png", Type_t::balloonButton);
	loadTexture("build/mouseEngine.png", Type_t::mouseEngine);
	

	loadTexture("build/basketButton.png", Type_t::basketButton);
	loadTexture("build/baseButton.png", Type_t::baseButton);
	loadTexture("build/bowlingButton.png", Type_t::bowlingButton);
	loadTexture("build/conveyorButton.png", Type_t::conveyorButton);
	loadTexture("build/brickButton.png", Type_t::brickWallButton);
	loadTexture("build/resizeButton.png", Type_t::resizeButton);
	loadTexture("build/rotateButton.png", Type_t::rotateButton);
	loadTexture("build/mouseEngineButton.png", Type_t::mouseEngineButton);
	loadTexture("build/beltButton.png", Type_t::beltButton);

	loadTexture("build/engineConectButton.png", Type_t::connectButton);


  	loadTexture("build/arrowLButton.png", Type_t::arrowLButton);
	loadTexture("build/arrowRButton.png", Type_t::arrowRButton);
  

  	loadTexture("build/advanceButton.png", Type_t::advanceButton);
	loadTexture("build/puzzleComplete.png", Type_t::puzzleComplete);
	loadTexture("build/replayButton.png", Type_t::replayButton);

	loadTexture("build/play.png", Type_t::play);
	loadTexture("build/exit.png", Type_t::exitButton);
	loadTexture("build/playmenu.png", Type_t::startButton);
	loadTexture("build/bomb.png", Type_t::reset);
	loadTexture("build/sound.png", Type_t::sound);

	loadTexture("build/choseLevelMenu.png", Type_t::choseLevelMenu);
	loadTexture("build/playButton.png", Type_t::playButton);
	loadTexture("build/upButton.png", Type_t::upButton);
	loadTexture("build/downButton.png", Type_t::downButton);

	loadTexture("build/menuBackground.png", Type_t::menuBackground);
	loadTexture("build/frame.png", Type_t::frame);*/



	////---------- font ---win------
	 loadFont("kongtext.ttf", Font::kongtext);
	 loadFont("coue1255.fon", Font::coue1255);
	/* loadFont("build/kongtext.ttf", Font::kongtext);
	  loadFont("build/coue1255.fon", Font::coue1255);*/


	////---------- sound ----------
	//  loadSound("menu.ogg", Sound::menu);
	// loadSound("background.ogg", Sound::background);

	//loadSound("build/menu.ogg", Sound::menu);
	//loadSound("build/background.ogg", Sound::background);


	m_path = "levels.txt";
	/*m_path = "build/levels.txt";*/

}

void ResourceManager::loadTexture(std::string path, Type_t name)
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

