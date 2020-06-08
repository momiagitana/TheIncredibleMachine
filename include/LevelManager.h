#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "Level.h"
#include "FileHandler.h"
#include "Digger.h"

class LevelManager
{
public:

	LevelManager();
	void start(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures);
	void readLevels();
	void setTexts(sf::Font& font);

private:

	std::vector< sf::Text> m_texts;
	sf::Text m_levelCompleted;
	sf::Clock m_moveClock;
	sf::Clock m_gameclock;
	Board m_board;
	std::vector<Level> m_levels;
	bool m_sholdWeMove = false;
	unsigned int m_diggerLives = DIGGER_LIVES;
	unsigned m_numOfLevel = 0;
	unsigned m_score = 0;
	

	void setDatalBarInfo();
	void updateStats();
	bool whyIsDead(const std::vector<sf::Texture>& gameTextures);
	void draw(sf::RenderWindow& window);
	void shouldWeStartMove();
	void goToNextLevel(const std::vector<sf::Texture>& gameTextures);
	void InitializeData();
	void levelCompleted(sf::RenderWindow& window);
	void gameOver(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures)const;
	void win(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures)const;
	
};
