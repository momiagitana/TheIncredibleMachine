#pragma once
#include <vector>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "globals.h"
#include "GameObj.h"
#include "Level.h"
#include "Balloon.h"
#include "BaseBall.h"
#include "BasketBall.h"
#include "BrickWall.h"
#include "FileHandler.h"
#include "Conveyor.h"//fix all these
//#include "BowlingBall.h"


using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; 

class Board
{
public:

	Board(const boardObjects&, b2World& world);
	void setBoard(const boardObjects & objects, b2World& world);
	void draw(sf::RenderWindow& window, bool);
	bool tryToAdd(sf::Vector2f mouseLoc, Type_t currObj,b2World& world);
	Type_t handleClick(sf::Vector2f mouseLoc);
	void resetObjectsPositions();
	bool clickedOnMe(sf::Vector2f mouseLoc) { return true; }
	bool collides(GameObj* current);
	bool checkCollison(GameObj* obj2, GameObj* obj1);
	bool isItemInLoc(conditionToWinLoc) const;

	void saveLevelToFile();
	void wakeEmAllUp();

	void checkMouseOver(sf::Vector2f loc);
	void hideObjButtons() {setEveryoneElseFalse(-1);}//change for //NO_ONE


	void updateImgLocs();
	void setEveryoneElseFalse(int);
	bool isResizable(GameObj* curr) const;

	sf::Sprite m_levelBackground;
	std::vector <std::unique_ptr<GameObj>> m_objects;
	std::vector< ObjInfo> getObjInfo() const;
};
