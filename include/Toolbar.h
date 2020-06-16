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
	Toolbar(std::vector<std::pair<GameObject_t,int>> v);
	void setButton(std::pair<GameObject_t, int> p);
	void draw(sf::RenderWindow& window);
	void setIdxLoc();
	bool clickedOnMe(sf::Vector2f loc);
	GameObject_t toolbarClick(sf::Vector2f loc);
	
private:
	void setDefalutToolbar();
	std::vector<std::pair<GameObject_t,int>> m_DATA;
	sf::RectangleShape m_rec;
	std::vector<std::shared_ptr<Button>> m_toolbar;
	int m_Idxloc;

};