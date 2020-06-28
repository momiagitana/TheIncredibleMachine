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

//#include "BowlingBall.h"


using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; 

class Board
{
public:

	Board(const boardObjects&, b2World& world);
	void setBoard(const boardObjects & objects, b2World& world);
	void draw(sf::RenderWindow& window, bool);//fix const?
	void drawTinyBoard (sf::RenderTexture& tinyBoard) const;
	bool tryToAdd(std::shared_ptr<GameObj>);
	std::shared_ptr<GameObj> handleClick(sf::Vector2f mouseLoc);
	void resetObjectsPositions();


  //zalman muti------------------
// 	bool clickedOnMe(sf::Vector2f mouseLoc) { return true; }
// 	bool collides(GameObj& current);
// 	bool checkCollison(GameObj& obj2, GameObj& obj1);
// 	void wakeEmAllUp();
// 	bool isItemInLoc(conditionToWinLoc) const;

// 	void testCollison(b2World& world );
// 	bool collision(GameObj& one, GameObj& two);

//master--------------
	bool clickedOnMe(sf::Vector2f mouseLoc) const;
	// bool collides(GameObj* current);//fix const
	// bool checkCollison(GameObj* obj2, GameObj* obj1);
	bool checkCollison(GameObj& obj2, GameObj& obj1);
	bool collides(GameObj& current);
	bool isItemInLoc(conditionToWinLoc) const;

	void saveLevelToFile();
	void wakeEmAllUp();

	void checkMouseOver(sf::Vector2f loc);
	void hideObjButtons() {setEveryoneElseFalse(-1);}//change for //NO_ONE

	GameObj* getObjWithId(const int);

	Collisions getCollisionObj()
	{
		return m_collision;
	}


private:


  //zalman muti------------------
	Collisions m_collision;
	

	void updateImgLocs();
	void setEveryoneElseFalse(int);
	bool isResizable(GameObj* curr) const;

	std::vector <std::shared_ptr<GameObj>> m_objects;
	std::vector< ObjInfo> getObjInfo() const;
	sf::RectangleShape m_background;

};
