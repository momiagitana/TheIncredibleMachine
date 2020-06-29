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
#include "MyListener.h"


class OverallController
{
public:

	OverallController(b2World& world, MyListener& listener);
	void run();
	
private:

	void draw(sf::RenderWindow& window);
	void setButtons();
	void volumeUp();
	void closeWindow();
	void setLevel();
	void chooseLevel();
	Type_t getSelection(sf::Vector2f loc) const;
	void handleClick(sf::Vector2f loc);
	void handleMouseMove(sf::Vector2f mouseLoc);

	std::vector<Button> m_buttons;
	sf::RenderWindow m_window;
	std::vector<Level> m_levels;
	b2World& m_world;
	BaseImg m_background;
	sf::Text m_text;
	unsigned m_numOfLevel = 0;
	LevelController m_levelController;
	sf::RenderTexture m_smallBoard;
};
sf::IntRect getIntRectOfMenuIcon(int i);
