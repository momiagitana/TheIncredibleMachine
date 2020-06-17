#include "Level.h"


Level::Level()
{
	addToolbarObj(basketBall,3);
	addToolbarObj(baseBall,2);
	addToolbarObj(balloon,100);
	//addToolbarObj(brickWallH, 4);
	//addToolbarObj(bowlingBall,1);
	
	addBoardObj(baseBall,sf::Vector2f(440.f,160.f)); //id 0
	addBoardObj(baseBall,sf::Vector2f(150.f,150.f)); //id 1
	addBoardObj(baseBall,sf::Vector2f(200.f,200.f));
	addBoardObj(basketBall,sf::Vector2f(100.f,300.f));
	addBoardObj(balloon, sf::Vector2f(300, 200)); //id = 4
	addBoardObj(brickWallH, sf::Vector2f(40,8));
	addBoardObj(brickWallH, sf::Vector2f(120,8));
	addBoardObj(brickWallH, sf::Vector2f(200,8));
	addBoardObj(brickWallH, sf::Vector2f(280,8));
	addBoardObj(brickWallH, sf::Vector2f(360,8));
	//addBoardObj(brickWallH, sf::Vector2f(440,8));
	addBoardObj(brickWallH, sf::Vector2f(520,8));
	addBoardObj(brickWallH, sf::Vector2f(600,8));
	addBoardObj(brickWallH, sf::Vector2f(680,8));
	addBoardObj(brickWallH, sf::Vector2f(0,592));
	addBoardObj(brickWallH, sf::Vector2f(80,592));
	addBoardObj(brickWallH, sf::Vector2f(160,592));
	addBoardObj(brickWallH, sf::Vector2f(240,592));
	addBoardObj(brickWallH, sf::Vector2f(320,592));
	addBoardObj(brickWallH, sf::Vector2f(400,592));
	addBoardObj(brickWallH, sf::Vector2f(480,592));
	addBoardObj(brickWallH, sf::Vector2f(560,592));
	addBoardObj(brickWallH, sf::Vector2f(620,592));
	//addBoardObj(bowlingBall, sf::Vector2f(400, 200));

	addCondLoc (0, sf::Vector2f(100,16), sf::Vector2f(440,0)); //object id=0 has to be inside the square with pos 200,200 and size 100,100
	//addCondAct (4); //balloon with id 4 has to be O
}

void Level::addBoardObj(GameObject_t obj, sf::Vector2f loc)
{
	m_initial.push_back(std::pair(obj,loc));
}

void Level::addToolbarObj (GameObject_t obj, int amount)
{
	m_toolbar.push_back(std::pair(obj, amount));
}

void Level::addCondLoc (int id, sf::Vector2f loc, sf::Vector2f size)
{
	m_locConditons.push_back(std::pair(id,std::pair(loc, size)));
}

void Level::addCondAct (int id)
{
	m_actConditions.push_back(id);
}