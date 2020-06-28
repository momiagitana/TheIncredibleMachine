#include "OverallController.h"
#include <iostream>
#include "ResourceManager.h"



OverallController::OverallController(b2World& world, MyListener& listener)//fix change name to menu
	:m_world(world),
	m_levels(FileHandler(ResourceManager::instance().getLevelPath(), true).readLevels()), //fix true->OPEN
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine", sf::Style::Default),
	m_background(sf::Vector2f(MENU_X, MENU_Y), menuBackground),
	m_levelController(m_levels[m_numOfLevel], world, m_window, listener)//fix
{
 
	m_window.setFramerateLimit(60);
	m_smallBoard.create(TINY_BOARD_W, TINY_BOARD_H);
	m_levelController.drawTinyBoard(m_smallBoard);

	for (int i = exitButton; i < none; i++)
		m_buttons.emplace_back(sf::Vector2f(0, 0), Type_t(i));
	setButtons();
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

			case sf::Event::MouseButtonReleased:

				sf::Vector2f location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				handleClick(location);
			
			}
		}
	}
}

void OverallController::handleClick(sf::Vector2f loc)
{
	switch (getSelection(loc))
	{
	case startButton:
	{
		if (m_levelController.run())//won level
		{
			++m_numOfLevel;
			setLevel();
		}
		m_levelController.drawTinyBoard(m_smallBoard);
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

Type_t OverallController::getSelection(sf::Vector2f loc) const
{
	for (auto button : m_buttons)
		if (button.mouseOnMe(loc))
			return button.getType();
	return none;
}

void OverallController::draw(sf::RenderWindow& window)
{
	sf::Sprite tinyBoard(m_smallBoard.getTexture());
	tinyBoard.setPosition(268,70);//fix

	m_levelController.drawStatic(false);
	m_window.draw(tinyBoard);
	m_background.draw(window);

	for (auto& button : m_buttons)
		button.draw(window);

	//window.draw(m_text);
}

void OverallController::setButtons()
{
	for (auto i = 0; i < m_buttons.size()-1; i++)
	{
		m_buttons[i].setIntRect(getIntRectOfMenuIcon(i));
		m_buttons[i].setPosition(sf::Vector2f(MENU_BUTTONS_LOC[i][0], MENU_BUTTONS_LOC[i][1]));
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
}

void OverallController::chooseLevel()
{	
	int level = -1;
	
	while(level >= m_levels.size() || level < 0)
	{
		std::cout << "please which level you want:\n";
		std::cin >> level;	
	}
	
	m_numOfLevel = level;
	setLevel();
}

sf::IntRect getIntRectOfMenuIcon(int i)
{
	return sf::IntRect(sf::Vector2i(1, 1), sf::Vector2i(MENU_BUTTONS_INT_RECT[i][0], MENU_BUTTONS_INT_RECT[i][1]));
}