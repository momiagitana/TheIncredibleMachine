#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.h"

using boardPair 	 = std::pair<GameObject_t, sf::Vector2f>;
using toolbarPair 	 = std::pair<GameObject_t, int>;

using conditionToWinLoc = std::pair<int, std::pair<sf::Vector2f, sf::Vector2f>>; //id of object that needs to be in the square with sqLoc, sqSize
using conditionToWinAct = int;	//id that needs to be on

using boardObjects   = std::vector<boardPair>;
using toolbarObjects = std::vector<toolbarPair>;

using conditionsLocs = std::vector<conditionToWinLoc>;
using conditionsActs = std::vector<conditionToWinAct>;

class Level
{
public:
	Level();

	void addBoardObj   (GameObject_t, sf::Vector2f);
	void addToolbarObj (GameObject_t, int);

	void addCondLoc (int, sf::Vector2f, sf::Vector2f);
	void addCondAct (int);


	//------option 1, check with yechezkel

	boardPair 	getFromBoard(int i) 	const { return m_initial[i]; }
	toolbarPair getFromToolbar(int i) 	const { return m_toolbar[i]; }
	
	conditionToWinLoc getFromCondLoc(int i) const { return m_locConditons[i]; }
	conditionToWinAct getFromCondAct(int i) const { return m_actConditions[i]; }
	

	int getBoardSize() 	const { return m_initial.size(); }
	int getToolSize() 	const { return m_toolbar.size(); }

	int getCondLocSize() 	const { return m_locConditons.size(); }
	int getCondActSize() 	const { return m_actConditions.size(); }


	//---------option 2

	boardObjects   getBoardObjs() const { return m_initial; }
	toolbarObjects getToolbarObjs() const {return m_toolbar; }

	conditionsLocs getLocConditions() const { return m_locConditons; }
	conditionsActs getActConditions() const { return m_actConditions; }

private:

	boardObjects   m_initial;
	toolbarObjects m_toolbar;

	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

};
