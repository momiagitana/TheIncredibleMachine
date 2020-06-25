#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<memory>



#include "ResourceManager.h"
#include "Button.h"
#include "Board.h"
#include "globals.h"
#include "FileHandler.h"
#include "LevelController.h"
#include "Level.h"

class OverallController
{
public:

	OverallController(b2World& world);
	void run();
	
private:

	void draw(sf::RenderWindow& window);
	void setButtons();
	void volumeUp();
	void closeWindow();
	void setLevel();
	void chooseLevel();

	std::vector<Button> m_buttons;
	sf::RenderWindow m_window;
	std::vector<Level> m_levels;
	b2World& m_world;
	BaseImg m_background;
	sf::Text m_text;
	unsigned m_numOfLevel = 0;
};
sf::IntRect getIntRectOfMenuIcon(int i);