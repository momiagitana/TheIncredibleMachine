#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"
#include "globals.h"

class GameMenu
{
public:

	GameMenu();
	void runstart(sf::RenderWindow& window);
	void settexturs( sf::RenderWindow&);
	void draw(sf::RenderWindow& window);
	bool shouldStartplaying()const;

private:
	void setSprits(sf::RenderWindow& window);
	bool m_StartPlaying = false;
	std::vector<sf::Sprite> m_sprits;
	sf::Text m_text;
};
