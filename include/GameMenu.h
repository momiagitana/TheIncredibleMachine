#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "globals.h"
#include "Button.h"
#include "baseImg.h"
class GameMenu
{
public:

	GameMenu();
	void runstart(sf::RenderWindow& window);
	void settexturs( sf::RenderWindow&);
	void draw(sf::RenderWindow& window);
	bool shouldStartplaying()const;

private:
	void setButtons();
	bool m_StartPlaying = false;
	std::vector<Button> m_buttons;
	BaseImg m_background;
	sf::Text m_text;
};
