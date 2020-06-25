#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "globals.h"
#include "Button.h"

class GameMenu
{
public:

	GameMenu();
	Type_t runStart(sf::RenderWindow& window);
	
	int getLevel()const;

private:
	void draw(sf::RenderWindow& window);
	void setButtons();
	std::vector<Button> m_buttons;
	BaseImg m_background;
	sf::Text m_text;
	unsigned m_numOfLevel = 0;
};

sf::IntRect getIntRectOfMenuIcon(int i);