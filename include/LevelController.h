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

	LevelController(const Level&, b2World& world);

	void run();


private:

	Board m_board;
	sf::RenderWindow& m_window;
	b2World& m_world;
	GameObject_t m_selected;
	Toolbar m_toolbar;
	
	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

	bool tryRunning();


};
