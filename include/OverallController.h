#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include<string>
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
	void drawMenu(sf::RenderWindow& window);
	void drawChoseLevel(sf::RenderWindow& window);
	void setButtons();
	void volumeUp();
	void closeWindow();
	void setLevel();
	Type_t getSelection(sf::Vector2f loc) const;
	void handleClick(sf::Vector2f loc);
	void handleMouseMove(sf::Vector2f mouseLoc);
	void menuMode(sf::Vector2f loc);
	void createLevel();
	void saveLevelToFile();
	void chooseLevelMode(sf::Vector2f loc);
	void drawTexts(sf::RenderWindow& window);
	void setMenuTexts();
	void setChoseLevelTexts();
	void setText();
	

	std::vector<ClickButton> m_menuButtons;
	std::vector<ClickButton> m_choseLevelButtons;
	sf::RenderWindow m_window;
	std::vector<Level> m_levels;
	b2World& m_world;
	BaseImg m_background;
	BaseImg m_choseLevelMenu;
	sf::Text m_levelGoal;
	sf::Text m_levelName;
	sf::Text m_levelNo;
	int m_numOfLevel = 0;
	LevelController m_levelController;
	sf::RenderTexture m_smallBoard;
	int m_choseMode = 0;
};
sf::IntRect getIntRectOfMenuIcon(int i);
sf::IntRect getIntRectOfChoseLevelIcon(int i);
