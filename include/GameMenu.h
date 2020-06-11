#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Globals.h"

class GameMenu
{
public:

	GameMenu();
	void runstart(sf::RenderWindow& window);
	void settexturs(const std::vector<sf::Texture>& textures, const sf::Font& font, sf::RenderWindow&);
	void draw(sf::RenderWindow& window);
	bool shouldStartplaying()const;

private:
	void setSprits(sf::RenderWindow& window);
	bool m_StartPlaying = false;
	std::vector<sf::Sprite> m_sprits;
	sf::Text m_text;
};
