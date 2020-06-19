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
//#include "BowlingBall.h"


using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; 

class Board
{
public:

	Board(const Level& level, b2World& world);
	void setBoard(const Level& level, b2World& world);
	void draw(sf::RenderWindow& window);
	bool tryToadd(sf::Vector2f mouseLoc, GameObject_t currObj,b2World& world);
	GameObject_t handleClick(sf::Vector2f mouseLoc);
	void resetObjectsPositions();
	//bool tryToAdd(sf::Vector2f loc, GameObject_t,b2World& world);
	bool clickedOnMe(sf::Vector2f mouseLoc) { return true; }
	bool collides(GameObj* current);
	bool checkCollison(GameObj* obj2, GameObj* obj1);
	void wakeEmAllUp();
	bool isItemInLoc(conditionToWinLoc) const;

	//bool levelFinished();
	//void MoveObjects(sf::Time deltaTime);

private:


	sf::Sprite m_levelBackground;
	std::vector <std::unique_ptr<GameObj>> m_objects;
	
};
