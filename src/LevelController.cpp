#include "LevelController.h"

#include <iostream>

LevelController::LevelController() {}

void LevelController::start(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures)
{
	InitializeData();
	//m_board.setBoard(m_levels[m_numOfLevel], gameTextures);
	updateStats();

	while (window.isOpen())
	{
		//updateStats();
		
		
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
		
	}
}


void LevelController::draw(sf::RenderWindow& window)
{
	//m_board.drowBoard(window);
	for (int i = 0; i < m_texts.size(); ++i)
	{
		window.draw(m_texts[i]);
	}
}


void LevelController::readLevels()
{
	FileHandler file(FILE_NAME);

	/*while (!file.ifEndOfFile())
	{
		Level level = file.readLevelFromFile();
		m_levels.push_back(level);
	}*/
}

void LevelController::setTexts(sf::Font& font)
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

void LevelController::setDatalBarInfo()
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

void LevelController::updateStats()
{
	
}

void LevelController::goToNextLevel(const std::vector<sf::Texture>& gameTextures)
{
	
	//m_board.setBoard(m_levels[m_numOfLevel], gameTextures);
}

void LevelController::InitializeData()
{
	m_numOfLevel = 0;
	m_score = 0;

}

void LevelController::levelCompleted(sf::RenderWindow& window)
{
	sf::Clock clock;
	window.draw(m_levelCompleted);
	window.display();
	while (clock.getElapsedTime().asSeconds() < 1) {}
}

void LevelController::gameOver(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures)const
{
	
}

void LevelController::win(sf::RenderWindow& window, const std::vector<sf::Texture>& gameTextures) const
{
	
}
