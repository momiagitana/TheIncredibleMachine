#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.h"
 

//using boardPair 	 = std::pair<Type_t, sf::Vector2f>;
using toolbarPair 	 = std::pair<Type_t, int>;

using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; //id of object that needs to be in the square with sqSize, sqLoc
using conditionToWinAct = int;	//id that needs to be on

using boardObjects   = std::vector<ObjInfo>;// changed
using toolbarObjects = std::vector<toolbarPair>;

using conditionsLocs = std::vector<conditionToWinLoc>;
using conditionsActs = std::vector<conditionToWinAct>;
 
class Level
{
public:
	Level();

	void addBoardObj(ObjInfo);
	void addToolbarObj(Type_t, int);

	void addCondLoc (int, sf::Vector2f, sf::Vector2f);
	void addCondAct (int);

	void addName(const std::string&);
	void addLevelGoal(const std::string&);

	std::string getLevelName() const { return m_name; }
	std::string getLevelGoal() const { return m_levelGoal; }

	boardObjects   getBoardObjs() const { return m_initial; }
	toolbarObjects getToolbarObjs() const {return m_toolbar; }

	conditionsLocs getLocConditions() const { return m_locConditons; }
	conditionsActs getActConditions() const { return m_actConditions; }

private:

	boardObjects   m_initial;
	toolbarObjects m_toolbar;

	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

	std::string m_name;
	std::string m_levelGoal;
};
