#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Globals.h"
#include "GameMenu.h"
#include "FileHandler.h"
#include "LevelManager.h"



class OverallController
{
public:

	OverallController();
	void run();
	
private:

	sf::RenderWindow m_window;
	LevelManager m_levelManager;
	GameMenu m_menu;

};
