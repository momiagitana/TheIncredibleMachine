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
	void add(const toolbarPair& pair);
	void Delete(const GameObject_t&obj);
	void draw(sf::RenderWindow& window);


private:
	void locationAddjuste();
	void setbar();
	void setplayButton();
	void setarrowsButton();
    toolbarObjects m_DATA;
	toolbar m_toolbar;
	int m_IdxPosAddjustue;
	sf::RectangleShape m_Bar;

	std::unique_ptr<Button> m_play;
	std::unique_ptr<Button> m_arrows;

};



















