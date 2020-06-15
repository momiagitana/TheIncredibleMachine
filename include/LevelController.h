#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Board.h"
#include "Level.h"
#include "Toolbar.h"
#include "globals.h"


class LevelController
{
public:

	LevelController(const Level&, b2World& world, sf::RenderWindow&);

	void run();

	bool clickOnToolbar(const sf::Vector2f );
	bool clickOnBoard(const sf::Vector2f);
	bool levelStatus();
	bool setlevelStatus(const bool);
	void updateMouseImg(const sf::Vector2f loc);
	void updateMouseLoc(const sf::Vector2f);
	void drawAll();


private:

	Board m_board;
	sf::RenderWindow& m_window;
	b2World& m_world;
	GameObject_t m_selected;
	Toolbar m_toolbar;

	bool m_notFinished = true;
	BaseImg m_currObj;

	
	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

	bool tryRunning();



};
