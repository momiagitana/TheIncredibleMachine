#include "LevelManager.h"

#include <iostream>

LevelManager::LevelManager() {}

void LevelManager::start(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures)
{
	InitializeData();
	m_board.setBoard(m_levels[m_numOfLevel], gameTextures);
	updateStats();

	sf::Music music;

	music.openFromFile("sonic_for_game.ogg");

	music.play();
	while (window.isOpen())
	{
		updateStats();
		shouldWeStartMove();
		auto deltaTime = m_moveClock.restart();
		window.clear();

		draw(window);
		window.display();
		auto event = sf::Event{};
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))

					window.close();
			}
			}
		}
		if (m_sholdWeMove)
		{
			if (m_board.levelFinished())
			{
				m_score += 20;
				m_numOfLevel++;

				if (m_numOfLevel < m_levels.size())
				{
					window.display();
					levelCompleted(window);
					goToNextLevel(gameTextures);
				}
				else
				{
					m_score += m_diggerLives * 150;
					win(window, gameTextures);
					InitializeData();
					m_sholdWeMove = false;
					return;//you win	
				}
			}

			if (m_board.isDiggerDead())
			{
				m_sholdWeMove = false;
				m_diggerLives--;
				if (!whyIsDead(gameTextures))
				{
					gameOver(window, gameTextures);
					return;
				}
				m_board.setDiggerAlive(false);
			}
			m_board.MoveObjects(deltaTime);
			setDatalBarInfo();

		}
	}
}

bool LevelManager::whyIsDead(const std::vector<sf::Texture>& gameTextures)
{
	
		m_board.resetLoc();
		m_gameclock.restart();
		while (m_gameclock.getElapsedTime().asSeconds() < 0.5) {}
		return true;
	
	return false;
}

void LevelManager::draw(sf::RenderWindow& window)
{
	m_board.drowBoard(window);
	for (int i = 0; i < m_texts.size(); ++i)
	{
		window.draw(m_texts[i]);
	}
}


void LevelManager::readLevels()
{
	FileHandler file(FILE_NAME);

	while (!file.ifEndOfFile())
	{
		Level level = file.readLevelFromFile();
		m_levels.push_back(level);
	}
}

void LevelManager::setTexts(sf::Font& font)
{
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::Yellow);
	text.setStyle(sf::Text::Regular);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);

	for (int i = 0; i < NUM_OF_TOOLBAR_INFO; ++i)
	{
		m_texts.push_back(text);
	}

	setDatalBarInfo();
	for (int i = 0; i < NUM_OF_TOOLBAR_INFO; ++i)
	{
		m_texts[i].setOrigin(m_texts[i].getGlobalBounds().width / 2, m_texts[i].getGlobalBounds().height / 2);
		m_texts[i].setPosition(sf::Vector2f((float)100 + (i * 200), (float)(WINDOW_HEIGHT - (TOOLBAR_SPACE / 2))));
	}

	m_levelCompleted.setFont(font);
	m_levelCompleted.setCharacterSize(80);
	m_levelCompleted.setFillColor(sf::Color::White);
	m_levelCompleted.setStyle(sf::Text::Regular);
	m_levelCompleted.setOutlineColor(sf::Color::Black);
	m_levelCompleted.setOutlineThickness(3);
	m_levelCompleted.setString("LEVEL COMPLETED");
	m_levelCompleted.setPosition(sf::Vector2f(150.f, (float)(WINDOW_HEIGHT / 2) + -20));
}

void LevelManager::setDatalBarInfo()
{
	std::string str;
	
	str = "TIME LEFT : ";
	if (m_board.getTime() == -1)
	{
		str.append("no time");
	}
	else
	{
		str.append(std::to_string(m_board.getTime()));
	}

	m_texts[TIME].setString(str);
	str = "SCORE : ";
	str.append(std::to_string(m_score));
	m_texts[SCORE].setString(str);
	str = "LEVEL : ";
	str.append(std::to_string(m_numOfLevel + 1));
	m_texts[LEVEL].setString(str);
}

void LevelManager::updateStats()
{
	if (m_board.getTime() != -1)
	{
		if (m_gameclock.getElapsedTime().asSeconds() > 1)
		{
			if (m_board.getTime() == 0)
			{
				m_board.setDiggerAlive(true);
			}
			else
			{
				m_board.setTime(m_board.getTime() - 1);
			}
			m_gameclock.restart();
		}
	}
}

void LevelManager::shouldWeStartMove()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_sholdWeMove = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_sholdWeMove = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_sholdWeMove = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_sholdWeMove = true;
	}

}

void LevelManager::goToNextLevel(const std::vector<sf::Texture>& gameTextures)
{
	m_sholdWeMove = false;
	m_board.setBoard(m_levels[m_numOfLevel], gameTextures);
}

void LevelManager::InitializeData()
{
	m_numOfLevel = 0;
	m_score = 0;

}

void LevelManager::levelCompleted(sf::RenderWindow& window)
{
	sf::Clock clock;
	window.draw(m_levelCompleted);
	window.display();
	while (clock.getElapsedTime().asSeconds() < 1) {}
}

void LevelManager::gameOver(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures)const
{
	sf::Clock clock;
	sf::Sprite sprite;
	sprite.setTexture(gameTextures[O_GAME_OVER]);
	sprite.scale((WINDOW_WIDTH / sprite.getGlobalBounds().width), (WINDOW_HEIGHT / sprite.getGlobalBounds().height));
	window.clear();
	window.draw(sprite);
	window.display();
	while (clock.getElapsedTime().asSeconds() < 3) {}
}

void LevelManager::win(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures) const
{
	sf::Clock clock;
	sf::Sprite sprite;
	sprite.setTexture(gameTextures[O_WIN]);
	sprite.scale((WINDOW_WIDTH / sprite.getGlobalBounds().width), (WINDOW_HEIGHT / sprite.getGlobalBounds().height));
	window.clear();
	window.draw(sprite);
	window.display();
	while (clock.getElapsedTime().asSeconds() < 3) {}
}
