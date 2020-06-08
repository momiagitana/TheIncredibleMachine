#pragma once
#include <vector>
#include <fstream>
#include<memory>
#include <SFML/Graphics.hpp>
#include "Digger.h"
#include "Level.h"
#include "Wall.h"
#include "DumbMonster.h"
#include "SmartMonster.h"
#include "Stone.h"
#include "Diamond.h"
#include "ExtraTime.h"
#include "ExtraScore.h"
#include "ExtraStons.h"



class Board
{
public:

	Board();
	void setBoard(const Level& level, const std::vector<sf::Texture>& gameTextures);
	void drowBoard(sf::RenderWindow& window);
	void resetLoc();
	int getDiggerStones()const;
	int getTime()const;
	void setTime(int levelTime);
	bool isDiggerDead()const;
	void setDiggerAlive(bool isdead);
	void handleCollisions(BaseObject& baseobject);
	bool levelFinished();
	void MoveObjects(sf::Time deltaTime);
	bool isDiamondEaten()const;
	bool shouldWeAddTime()const;
	bool shouldWeAddScore()const;

private:

	Digger m_digger;
	int m_numOfDiamond = 0;
	bool m_diamondIsEaten = false;
	std::vector<std::unique_ptr<Monster>> m_monsters;
	std::vector<std::unique_ptr<NoneMoving>> m_noneMoveObjects;
	int m_rows = 0;
	int m_cols = 0;
	int m_time = -1;
	sf::Sprite m_levelBackground;
	void InitializeData();
	void MoveDigger(sf::Time deltaTime);
	void MovMonsters(sf::Time deltaTime);
};
