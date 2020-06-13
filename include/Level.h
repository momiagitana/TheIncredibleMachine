#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "globals.h"

using boardPair 	 = std::pair<GameObject_t, sf::Vector2f>;
using toolbarPair 	 = std::pair<GameObject_t, int>;

using boardObjects   = std::vector<boardPair>;
using toolbarObjects = std::vector<toolbarPair>;

class Level
{
public:
	Level();

	void addBoardObj   (GameObject_t, sf::Vector2f);
	void addToolbarObj (GameObject_t, int);

	boardPair 	getFromBoard(int i) 	const { return m_initial[i]; }
	toolbarPair getFromToolbar(int i) 	const { return m_toolbar[i]; }
	
	int getBoardSize() 	const { return m_initial.size(); }
	int getToolSize() 	const { return m_toolbar.size(); }

private:

	boardObjects   m_initial;
	toolbarObjects m_toolbar;

};
