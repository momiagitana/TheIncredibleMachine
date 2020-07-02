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
#include "BowlingBall.h"
#include "BrickWall.h"
#include "Collisions.h"
#include "FileHandler.h"
#include "Conveyor.h"//fix all these
#include "MouseEngine.h"
#include "Connections.h"
#include "Connectable.h"

//#include "BowlingBall.h"


using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; 

class Board
{
public:

	Board(const boardObjects&, b2World& );
	void setBoard(const boardObjects& , b2World&);
	void draw(sf::RenderWindow&, const bool);//fix const?
	void drawTinyBoard (sf::RenderTexture&) const;
	bool tryToAdd(const std::shared_ptr<GameObj>, const Type_t); 
	std::shared_ptr<GameObj> handleClick(const sf::Vector2f, Type_t&);
	void resetObjectsPositions();

	bool clickedOnMe(const sf::Vector2f) const;
	bool checkCollison(const GameObj& obj2, const GameObj& obj1) const;
	bool collides(const GameObj&) const;
	bool isItemInLoc(const conditionToWinLoc) const;

	void saveLevelToFile() const;
	void wakeEmAllUp(); //need to delete func????

	void checkMouseOver(const sf::Vector2f ,const std::shared_ptr<GameObj>);
	void hideObjButtons() {setEveryoneElseFalse(-1);}//change for //NO_ONE


	GameObj* getObjWithId(const int) const;

	Collisions getCollisionObj() const { return m_collision;}

	bool tryConnecting(const sf::Vector2f);
	bool doneConnecting();
	void resetConnections() { m_connections.reset(); }
	void deleteConnection(Connectable* obj) { m_connections.deleteConnection(obj); }
	Connectable* isConnectedAndConnectable(GameObj* obj) const { return m_connections.isConnectedAndConnectable(obj); }
	void setMousePos(const sf::Vector2f, const std::shared_ptr<GameObj>);

private:

	Collisions m_collision; //fix see where to put it

	void updateImgLocs();
	void setEveryoneElseFalse(const int);
	std::vector< ObjInfo> getObjInfo() const;
	std::shared_ptr<GameObj> findConnectable(const sf::Vector2f) const; 

	std::vector <std::shared_ptr<GameObj>> m_objects;
	Connections m_connections;
	sf::RectangleShape m_background;

};
