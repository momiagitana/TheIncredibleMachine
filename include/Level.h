#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.h"

using boardPair 	 = std::pair<GameObject_t, sf::Vector2f>;
using toolbarPair 	 = std::pair<GameObject_t, int>;

using conditionToWinLoc = std::pair<int, sf::Vector2f>;
using conditionToWinAct = int;

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

	void addCondLoc (conditionToWinLoc);
	void addCondAct (conditionToWinAct);


	boardPair 	getFromBoard(int i) 	const { return m_initial[i]; }
	toolbarPair getFromToolbar(int i) 	const { return m_toolbar[i]; }
	
	conditionToWinLoc getFromCondLoc(int i) const { return m_locConditons[i]; }
	conditionToWinAct getFromCondAct(int i) const { return m_actConditions[i]; }
	

	int getBoardSize() 	const { return m_initial.size(); }
	int getToolSize() 	const { return m_toolbar.size(); }

	int getCondLocSize() 	const { return m_locConditons.size(); }
	int getCondActSize() 	const { return m_actConditions.size(); }

private:

	boardObjects   m_initial;
	toolbarObjects m_toolbar;

	conditionsLocs m_locConditons;
	conditionsActs m_actConditions;

};
