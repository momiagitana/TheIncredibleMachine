#include "OverallController.h"
#include <iostream>
#include "ResourceManager.h"



OverallController::OverallController(b2World& world, MyListener& listener)//fix change name to menu
	:m_world(world),
	m_levels(FileHandler(ResourceManager::instance().getLevelPath(), true).readLevels()), //fix true->OPEN
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine", sf::Style::Default),
	m_background(sf::Vector2f(MENU_X, MENU_Y), menuBackground),
	m_choseLevelMenu(sf::Vector2f(MENU_X, MENU_Y), choseLevelMenu),
	m_levelController(m_levels[m_numOfLevel], world, m_window, listener)//fix
{
	m_window.setFramerateLimit(60);
	m_smallBoard.create(TINY_BOARD_W, TINY_BOARD_H);
	
	for (int i = exitButton; i < endMenuButtons; i++)
		m_menuButtons.emplace_back(sf::Vector2f(0, 0), Type_t(i));
	for (int i = playButton; i < endChoseLevelButtons; i++)
		m_choseLevelButtons.emplace_back(sf::Vector2f(0, 0), Type_t(i));

	setButtons();
	setLevel();
	setText();
}

void OverallController::run()
{
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

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					closeWindow();
				break;

			case sf::Event::MouseButtonReleased:
			{
				auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				handleClick(location);
				break;
			}

			case sf::Event::MouseMoved:
				auto mouseLoc = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				handleMouseMove(mouseLoc);
				break;
			}
		}
	}
}

void OverallController::handleClick(sf::Vector2f loc)
{
	if (!m_choseLevelMode)
		menuMode(loc);
	else
		chooseLevelMode(loc);
}

void OverallController::chooseLevelMode(sf::Vector2f loc)
{
	
	switch (getSelection(loc))
	{
	case playButton:
	{
		m_choseLevelMode = false;
		return;
	}
	case upButton:
	{
		m_numOfLevel= (++m_numOfLevel)% m_levels.size();
		setLevel();
		return;
	}
	case downButton:
	{
		m_numOfLevel = (--m_numOfLevel) % m_levels.size();
		setLevel();
		return;
	}
	default:
		return;
	}
	
}

void OverallController::drawTexts(sf::RenderWindow& window)
{
	setText();
	window.draw(m_levelGoal);
	window.draw(m_levelName);
	window.draw(m_levelNo);
}

void OverallController::setMenuTexts()
{
	m_levelName.setPosition(LEVEL_NAME_TEXT_LOC_MENU);
	m_levelNo.setPosition(LEVEL_NO_TEXT_LOC_MENU);
}

void OverallController::setChoseLevelTexts()
{
	m_levelName.setPosition(LEVEL_NAME_TEXT_LOC_CHOSE_LEVEL);
	m_levelNo.setPosition(LEVEL_NO_TEXT_LOC_CHOSE_LEVEL);
}

void OverallController::setText()
{
	m_levelGoal.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_levelGoal.setString(m_levels[m_numOfLevel].getLevelGoal());
	m_levelGoal.setPosition(LEVEL_GOAL_TEXT_LOC);
	m_levelGoal.setColor(sf::Color::Black);
	m_levelGoal.setCharacterSize(CHARATER_SIZE);

	m_levelName.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_levelName.setString(m_levels[m_numOfLevel].getLevelName());
	m_levelName.setColor(sf::Color::Black);
	m_levelName.setCharacterSize(CHARATER_SIZE);

	m_levelNo.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_levelNo.setString("LEVEL:" + std::to_string(m_numOfLevel+1));
	m_levelNo.setColor(sf::Color::Black);
	m_levelNo.setCharacterSize(CHARATER_SIZE);
}

void OverallController::menuMode(sf::Vector2f loc)
{
	switch (getSelection(loc))
	{
	case startButton:
	{
		if (m_levelController.run())//won level
		{
			m_numOfLevel = m_numOfLevel+1 % m_levels.size();
			setLevel();
		}
		m_levelController.drawTinyBoard(m_smallBoard);
		return;
	}
	case exitButton:
	{
		closeWindow();
		return;
	}
	case sound:
	{
		volumeUp();
		return;
	}
	case reset:
	{
		setLevel();
		return;
	}
	case choseLevel:
	{
		m_choseLevelMode = true;
		return;
	}
	default:
		return;
	}
}

void OverallController::handleMouseMove(sf::Vector2f mouseLoc) //fix
{
	for (auto i = 0; i < m_menuButtons.size() ; i++)
	{
		if (m_menuButtons[i].mouseOnMe(mouseLoc))
		{
			switch (m_menuButtons[i].getType())
			{
			case startButton:
			{
				m_menuButtons[i].nextIntRect();
				break;
			}
			case exitButton:
			{
				m_menuButtons[i].nextIntRect();
				break;
			}
			case reset:
			{
				m_menuButtons[i].nextIntRect();
				break;
			}
			case choseLevel:
			{
				m_menuButtons[i].nextIntRect();
				break;
			}
			default:
				break;
			}
		}
		else
		{

			m_menuButtons[i].prevIntRect();
		}
	}
}

Type_t OverallController::getSelection(sf::Vector2f loc) const
{
	if (!m_choseLevelMode)
	{
		for (auto button : m_menuButtons)
			if (button.mouseOnMe(loc))
				return button.getType();
	}
	else
	{
		for (auto button : m_choseLevelButtons)
			if (button.mouseOnMe(loc))
				return button.getType();
	}
	return none;
}

void OverallController::draw(sf::RenderWindow& window)
{
	sf::Sprite tinyBoard(m_smallBoard.getTexture());
	tinyBoard.setPosition(268, 70);//fix

	m_levelController.drawStatic(false);
	m_window.draw(tinyBoard);
	
	if (!m_choseLevelMode)
	{
		setMenuTexts();
		drawMenu(window);
	}
	else
	{
		setChoseLevelTexts();
		drawChoseLevel(window);
	}
	drawTexts(window);
}

void OverallController::drawMenu(sf::RenderWindow& window)
{
	m_background.draw(window);
	for (auto& button : m_menuButtons)
		button.draw(window);
}

void OverallController::drawChoseLevel(sf::RenderWindow& window)
{
	m_choseLevelMenu.draw(window);
	for (auto& button : m_choseLevelButtons)
		button.draw(window);
}

void OverallController::setButtons()
{
	for (auto i = 0; i < m_menuButtons.size() ; i++)
	{
		m_menuButtons[i].setIntRect(getIntRectOfMenuIcon(i));
		m_menuButtons[i].setPosition(sf::Vector2f(MENU_BUTTONS_LOC[i][0], MENU_BUTTONS_LOC[i][1]));
	}
	for (auto i = 0; i <m_choseLevelButtons.size(); i++)
	{
		m_choseLevelButtons[i].setIntRect(getIntRectOfChoseLevelIcon(i));
		m_choseLevelButtons[i].setPosition(sf::Vector2f(CHOSE_LEVEL_BUTTONS_LOC[i][0], CHOSE_LEVEL_BUTTONS_LOC[i][1]));
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
	m_levelController.loadNewLevel(m_levels[m_numOfLevel]);
	m_levelController.drawTinyBoard(m_smallBoard);
}

sf::IntRect getIntRectOfMenuIcon(int i)
{
	return sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(MENU_BUTTONS_INT_RECT[i][0], MENU_BUTTONS_INT_RECT[i][1]));
}

sf::IntRect getIntRectOfChoseLevelIcon(int i)
{
	return sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(CHOSE_LEVEL_BUTTONS_INT_RECT[i][0], CHOSE_LEVEL_BUTTONS_INT_RECT[i][1]));
}
