#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Globals.h"
#include "GameMenu.h"
#include "FileHandler.h"
#include "LevelController.h"



class OverallController
{
public:

	OverallController();
	void run();
	
private:

	sf::RenderWindow m_window;
	LevelController m_levelController;
	GameMenu m_menu;

};
