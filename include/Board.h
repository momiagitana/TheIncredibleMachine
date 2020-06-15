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
//#include "BowlingBall.h"




class Board
{
public:

	Board(const Level& level, b2World& world);
	void setBoard(const Level& level, b2World& world);
	void draw(sf::RenderWindow& window);
	bool tryToadd(sf::Vector2f mouseLoc, GameObject_t currObj);
	GameObject_t handleClick(sf::Vector2f mouseLoc);
	void resetObjectsPossitions() {}
	bool tryToAdd(sf::Vector2f loc, GameObject_t) { return true; }
	bool clickedOnMe(sf::Vector2f mouseLoc) { return true; }


	//bool levelFinished();
	//void MoveObjects(sf::Time deltaTime);

private:


	sf::Sprite m_levelBackground;
	std::vector <std::unique_ptr<GameObj>> m_objects;
	
};
