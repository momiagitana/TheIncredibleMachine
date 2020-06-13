#pragma once
#include <vector>
#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "globals.h"

#include "Level.h"



class Board
{
public:

	Board();
	void setBoard(const Level& level);
	void drowBoard(sf::RenderWindow& window);
	//void resetLoc();
	
	int getTime()const;
	void setTime(int levelTime);

	//void handleCollisions(BaseObject& baseobject);
	bool levelFinished();
	void MoveObjects(sf::Time deltaTime);
	

private:


	sf::Sprite m_levelBackground;
	//void InitializeData();
	
};
