#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Board.h"
#include "Level.h"
#include "Toolbar.h"
//#include "globals.h"


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
	void drawAll(bool);
	//void removeMouseImage();


private:

	Board m_board;
	sf::RenderWindow& m_window;
	b2World& m_world;
	Toolbar m_toolbar;

	bool m_finished = false;

	Type_t m_selected = none;
	BaseImg m_mouseImg;
	BaseImg m_frame;
	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

	bool tryRunning();
	bool checkIfLevelFinished() const;
	void setSelected(Type_t, const sf::Vector2f);

};
