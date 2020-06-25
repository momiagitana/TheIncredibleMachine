#include "OverallController.h"
#include <iostream>
#include "ResourceManager.h"



OverallController::OverallController(b2World& world)
	:m_world(world), m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine", sf::Style::Default), m_background(sf::Vector2f((float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2), background)
{
	FileHandler file(ResourceManager::instance().getLevelPath());
	m_levels = file.readLevels();
	m_window.setFramerateLimit(60);

	for (int i = exitButton; i < none; i++)
		m_buttons.emplace_back(sf::Vector2f(0, 0), Type_t(i));
	setButtons();

	m_background.setPosition(sf::Vector2f((float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2));
	m_background.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));

}

void OverallController::run()
{
	auto levelControler = LevelController(m_levels[m_numOfLevel], m_world, m_window);
	while (m_window.isOpen())
	{
		m_window.clear();
		draw(m_window);
		m_window.display();
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				closeWindow();
				break;
			case sf::Event::KeyPressed:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					closeWindow();
			}
			case sf::Event::MouseButtonReleased:
			{
				sf::Vector2f location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				for (auto button : m_buttons)
				{
					if (button.clickedOnMe(location))
					{
						switch (button.getType())
						{
						case startButton:
						{
							if (levelControler.run())//won level
								++m_numOfLevel;
							break;
						}
						case exitButton:
						{
							closeWindow();
							break;
						}
						case sound:
						{
							volumeUp();
							break;
						}
						case reset:
						{
							setLevel();
							break;
						}
						case choseLevel:
						{
							chooseLevel();
							break;
						}
						default:
							break;
						}
					}
				}
				break;
			}
			/*if (m_numOfLevel < m_levels.size())
				++m_numOfLevel;
			else
				game finished*/
			}
		}
	}
}

void OverallController::draw(sf::RenderWindow& window)
{
	m_background.draw(window);

	for (auto& button : m_buttons)
		button.draw(window);
	window.draw(m_text);
}

void OverallController::setButtons()
{
	for (auto i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].setIntRect(getIntRectOfMenuIcon(i));
		m_buttons[i].setPosition(sf::Vector2f((WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + 100 + (i * 60)));
	}
}

void OverallController::volumeUp()
{
}

void OverallController::closeWindow()
{
	m_window.close();
}

void OverallController::setLevel()
{
	//levelControler = LevelController(m_levels[m_numOfLevel], m_world, m_window);
}

void OverallController::chooseLevel()
{
	std::cin >> m_numOfLevel;
	setLevel();
}

sf::IntRect getIntRectOfMenuIcon(int i)
{
	return sf::IntRect(sf::Vector2i(1, 1), sf::Vector2i(MENU_BUTTONS_INT_RECT[i][0], MENU_BUTTONS_INT_RECT[i][1]));
}