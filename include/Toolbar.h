#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;

using toolbarPair = std::pair<GameObject_t, int>;
using toolbarObjects = std::vector<toolbarPair>;
using toolbar = std::map<GameObject_t, std::unique_ptr<Button>>;

class Toolbar
{
	
public:
	Toolbar(toolbarObjects davavector);
	bool clickedOnMe(sf::Vector2f loc) const;
	GameObject_t handelclick(sf::Vector2f loc);
	void add(GameObject_t obj, int amount = 1);
	void Delete(const GameObject_t&obj);
	void draw(sf::RenderWindow& window);


private:
	void locationAddjuste();
	void setbar();
	void setplayButton();
	void setarrowsButton();
	toolbar m_toolbar;
	int m_indxPosAdjust;
	sf::RectangleShape m_Bar;

	std::unique_ptr<Button> m_play;
	std::unique_ptr<Button> m_arrows;

};



















