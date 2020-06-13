#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "globals.h"
#include "GameMenu.h"
#include "FileHandler.h"



class OverallController
{
public:

	OverallController();
	void run();
	
private:

	sf::RenderWindow m_window;
	//LevelController m_levelController;
	GameMenu m_menu;

};
