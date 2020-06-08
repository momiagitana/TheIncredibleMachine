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
	std::vector<sf::Texture> m_gameTextures;
	std::vector<sf::Texture> m_menuTextures;
	sf::Font m_font;

	void loadTextures();
};
