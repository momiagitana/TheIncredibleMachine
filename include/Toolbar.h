#pragma once
#include "Button.h"
#include "ToolbarButton.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;

using toolbarPair = std::pair<GameObject_t, int>;
using toolbarObjects = std::vector<toolbarPair>;
using toolbar = std::vector<ToolbarButton>;

class Toolbar
{
	
public:
	Toolbar(toolbarObjects davavector);
	bool clickedOnMe(sf::Vector2f loc) const;
	GameObject_t handleClick(sf::Vector2f loc);
	void add(GameObject_t obj, int amount = 1);
	void deleteObj(const GameObject_t&obj);
	void draw(sf::RenderWindow& window);


private:
	void setbar();
	void setPlayButton();
	void setArrowsButton();
	toolbar m_toolbar;
	int m_indxPosAdjust;
	sf::RectangleShape m_bar;

	std::unique_ptr<Button> m_play;
	std::unique_ptr<Button> m_arrows;

};


