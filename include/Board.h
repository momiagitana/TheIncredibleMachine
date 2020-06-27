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
#include "Collisions.h"
#include "FileHandler.h"
#include "Conveyor.h"//fix all these
#include "MouseEngine.h"
#include "Conections.h"

//#include "BowlingBall.h"


using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; 

class Board
{
public:

	Board(const boardObjects&, b2World& world);
	void setBoard(const boardObjects & objects, b2World& world);
	void draw(sf::RenderWindow& window, bool);//fix const?
	void drawTinyBoard (sf::RenderTexture& tinyBoard) const;
	bool tryToAdd(std::shared_ptr<GameObj>, Type_t);
	std::shared_ptr<GameObj> handleClick(sf::Vector2f mouseLoc);
	void resetObjectsPositions();

	bool clickedOnMe(sf::Vector2f mouseLoc) const;
	bool checkCollison(GameObj& obj2, GameObj& obj1);
	bool collides(GameObj& current);
	bool isItemInLoc(conditionToWinLoc) const;

	void saveLevelToFile();
	void wakeEmAllUp();

	void checkMouseOver(sf::Vector2f loc);
	void hideObjButtons() {setEveryoneElseFalse(-1);}//change for //NO_ONE
	bool tryConecting(sf::Vector2f mouseLoc);

private:

	void updateImgLocs();
	void setEveryoneElseFalse(int);
	bool isResizable(GameObj* curr) const;
	std::vector< ObjInfo> getObjInfo() const;

	std::vector <std::shared_ptr<GameObj>> m_objects;
	Conections m_conections;
	sf::RectangleShape m_background;

};
