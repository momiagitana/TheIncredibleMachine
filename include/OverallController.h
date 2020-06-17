#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include<memory>

#include "Board.h"
#include "globals.h"
#include "GameMenu.h"
#include "FileHandler.h"
#include "LevelController.h"
#include "Level.h"

class OverallController
{
public:

	OverallController(const Level&, b2World& world);
	void run();
	
private:

	sf::RenderWindow m_window;
	LevelController m_levelController;
	std::vector<Level> m_levels;
	b2World& m_world;
	GameMenu m_menu;

};
