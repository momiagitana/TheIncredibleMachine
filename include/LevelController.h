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

	bool run();

	bool clickOnToolbar(const sf::Vector2f );
	bool clickOnBoard(const sf::Vector2f);
	bool levelStatus();
	bool setlevelStatus(const bool);
	void createMouseImg(const sf::Vector2f loc);
	void updateMouseLoc(const sf::Vector2f);

	void whereAmI(sf::Vector2f);
	void clearMouse(Type_t type, const sf::Vector2f loc);

	bool replaySolution();

	void drawAll(bool);


private:

	Board m_board;
	sf::RenderWindow& m_window;
	b2World& m_world;
	Toolbar m_toolbar;

	bool m_finished = false;

	Type_t m_selected = none;
	std::shared_ptr<GameObj> m_mouseObj = nullptr;
	BaseImg m_mouseImg;

	BaseImg m_frame;
	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

	bool m_mouseOnToolBr = false;

	bool tryRunning();
	bool checkIfLevelFinished() const;
	void grabFromBoard(std::shared_ptr<GameObj> obj, sf::Vector2f loc);
	void createOnHandObj(sf::Vector2f loc);
	void setSelected(Type_t type, sf::Vector2f mouseLoc);

};
