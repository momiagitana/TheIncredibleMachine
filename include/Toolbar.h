#pragma once
#include "Button.h"
#include "ToolbarButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;

using toolbarPair = std::pair<Type_t, int>;
using toolbarObjects = std::vector<toolbarPair>;
using toolbar = std::vector<ToolbarButton>;

class Toolbar
{
	
public:
	Toolbar(toolbarObjects);
	bool clickedOnMe(sf::Vector2f ) const;
	Type_t handleClick(sf::Vector2f );
	void addOrIncrease(Type_t obj, int amount = 1);
	void deleteObj(const Type_t&);
	void draw(sf::RenderWindow&);

private:
	void add(Type_t, int);
	void updateLocs();
	void setBar();
	void setPlayButton();
	void setArrowsButton();

	toolbar m_toolbar;
	int m_page = 0;
	sf::RectangleShape m_bar;

	std::unique_ptr<Button> m_play;
	std::unique_ptr<Button> m_arrows;

};


