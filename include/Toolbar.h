#pragma once
#include "Button.h"
#include "globals.h"
#include "ResourceManager.h"
#include <string>
#include <sstream>
#include <map>
#include <SFML/Graphics.hpp>

using std::ostringstream;

using toolbarPair = std::pair<ResourceManager::ToolBarobj_t, int>;
using toolbarObjects = std::vector<toolbarPair>;

class Toolbar
{
public:
	Toolbar(toolbarObjects v);
	void setButton(toolbarPair p);
	void draw(sf::RenderWindow& window);
	void setIdxLoc();
	bool clickedOnMe(sf::Vector2f loc);
	ResourceManager::ToolBarobj_t toolbarClick(sf::Vector2f loc);
private:
	void setDefalutToolbar();
	toolbarObjects m_DATA;
	sf::RectangleShape m_rec;
	std::vector<std::shared_ptr<Button>> m_toolbar;
	int m_Idxloc;

};