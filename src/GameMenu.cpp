#include "GameMenu.h"

GameMenu::GameMenu() 
:m_background(sf::Vector2f((float)WINDOW_WIDTH/2, (float)WINDOW_HEIGHT/2), background)
{
	for (int i = exitButton; i < none; i++)
		m_buttons.emplace_back(sf::Vector2f(0,0), Type_t(i));
	setButtons();


	m_background.setPosition(sf::Vector2f((float)WINDOW_WIDTH/2, (float)WINDOW_HEIGHT/2));
	m_background.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
}



void GameMenu::runStart(sf::RenderWindow& window)
{

	while (window.isOpen())
	{
		window.clear();
		draw(window);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event))
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
			case sf::Event::MouseButtonReleased:
			{
				sf::Vector2f location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				for (auto button : m_buttons)
				{
					if (button.clickedOnMe(location))
					{
						if (button.getType() == startButton)
						{
							m_StartPlaying = true;
							return;
						}
						else if (button.getType() == exitButton)
						{
							m_StartPlaying = false;
							return;
						}
					}
				}
				break;
			}
			}
		}
	}
}

void GameMenu::draw(sf::RenderWindow& window)
{
	m_background.draw(window);
	
	for (auto& button : m_buttons)
		button.draw(window);


	window.draw(m_text);
}

bool GameMenu::shouldStartplaying()const
{
	return m_StartPlaying;
}

void GameMenu::setButtons()
{
	for (auto i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].setIntRect(getIntRectOfMenuIcon(i));
		m_buttons[i].setPosition(sf::Vector2f((WINDOW_WIDTH / 2), (WINDOW_HEIGHT / 2) + 100 + (i * 60)));
	}
		
}

sf::IntRect getIntRectOfMenuIcon(int i)
{
	return sf::IntRect(sf::Vector2i(1,1),sf::Vector2i(MENU_BUTTONS_INT_RECT[i][0],MENU_BUTTONS_INT_RECT[i][1]));
}