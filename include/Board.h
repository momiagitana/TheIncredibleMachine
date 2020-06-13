#pragma once
#include <vector>
#include <fstream>
#include<memory>
#include <SFML/Graphics.hpp>

#include "Level.h"
#include "BaseObject.h"


class Board
{
public:

	Board();
	void setBoard(const Level& level, const std::vector<sf::Texture>& gameTextures);
	void drowBoard(sf::RenderWindow& window);
	//void resetLoc();
	
	int getTime()const;
	void setTime(int levelTime);

	void handleCollisions(BaseObject& baseobject);
	bool levelFinished();
	void MoveObjects(sf::Time deltaTime);
	

private:

	
	int m_rows = 0;
	int m_cols = 0;
	int m_time = -1;
	sf::Sprite m_levelBackground;
	//void InitializeData();
	
};
