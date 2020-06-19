#pragma once
#include "Button.h"
#include "globals.h"
#include "ResourceManager.h"
#include <string>
#include <sstream>
#include <map>
#include <SFML/Graphics.hpp>

using std::ostringstream;

class Toolbar
{
public:

	Toolbar(std::vector<std::pair<GameObject_t, int>> v);
	
	GameObject_t handleClick(sf::Vector2f loc);
	
	void setButton(std::pair<GameObject_t, int> p);
	void draw(sf::RenderWindow& window);
	bool clickedOnMe(sf::Vector2f loc);
	void lightOne(sf::Vector2f loc);
	void UnlightOne(sf::Vector2f loc);
	void add(GameObject_t, int num_of_apear = 1);
	void lightAll();
	void UnlightAll();

	void holdThisObj(GameObject_t obj);
	void take(GameObject_t obj);
	void drope(GameObject_t obj);
	void putback(GameObject_t obj);

	GameObject_t toolbarClick(sf::Vector2f loc);
	GameObject_t getCurrent_at_Hold();

private:

	void setIdxLoc();
	void setDefalutToolbar();
	void setplayButton();
	void setplayArrowsButton();
	void setToolBaord();

	std::vector<std::pair<GameObject_t, int>> m_DATA;
	sf::RectangleShape m_rec;
	std::map<GameObject_t, std::shared_ptr<Button>> m_toolbar;
	int m_Idxloc;
	GameObject_t m_Current_at_hold;
};