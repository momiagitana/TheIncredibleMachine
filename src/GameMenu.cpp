#include "GameMenu.h"

GameMenu::GameMenu() : m_background(sf::Vector2f((float)WINDOW_WIDTH/2, (float)WINDOW_HEIGHT/2), ResourceManager::instance().getTexture(background))
{
	for (int i = exit_button; i < none; i++)
	{

		m_buttons.emplace_back(sf::Vector2f(((float)WINDOW_WIDTH / 2) - 50, ((float)WINDOW_HEIGHT / 2) + 110 + (i * 10)), GameObject_t(i));

	}

}

void GameMenu::settexturs(sf::RenderWindow& window)
{


	setSprits(window);

	/*m_text.setFont(ResourceManager::instance().getFont(0));
	m_text.setString("Ariel Gabel & Itzhak Vaknin");
	m_text.setCharacterSize(20);
	m_text.setFillColor(sf::Color::White);
	m_text.setStyle(sf::Text::Regular);
	m_text.setOrigin(0, 10);
	m_text.setPosition(120.f, (float)(WINDOW_HEIGHT / 1.10));*/
}

void GameMenu::runstart(sf::RenderWindow& window)
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
				sf::Vector2f location;
				if (sf::Mouse::Button::Left == event.mouseButton.button)
				{
					location = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				}
				for (auto button : m_buttons)
				{
					switch (button.clicked(location))
					{
					case start_button:
					{
						m_StartPlaying = true;
						return;
					}
					case exit_button:
					{
						m_StartPlaying = false;
						return;
					}

					}
				}

				break;
			}
			case sf::Event::MouseMoved:
				// Save the position of the mouse:

				auto mousePos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				for (auto button : m_buttons)
				{
					switch (button.clicked(mousePos))
					{
					case start_button:
					{
						m_buttons[M_START_BUTTON].setColor(sf::Color(255, 255, 255, 128));
						break;
					}
					case exit_button:
					{
						m_buttons[M_EXIT_BUTTON].setColor(sf::Color(255, 255, 255, 128));
						break;
					}
					default:
					{
						button.setColor(sf::Color::White);
						break;
					}
					}
				}

			}
		}
	}
}

void GameMenu::draw(sf::RenderWindow& window)
{
	for (auto buttons : m_buttons)
	{
		buttons.draw(window);
	}
	/*m_buttons[M_START_BUTTON].draw(window);
	m_buttons[M_EXIT_BUTTON].draw(window);*/
	m_background.draw(window);

	window.draw(m_text);
}

bool GameMenu::shouldStartplaying()const
{
	return m_StartPlaying;
}

void GameMenu::setSprits(sf::RenderWindow& window)
{
	m_buttons[M_RESET].setSize(sf::Vector2u(18, 31));
	m_buttons[M_VOL_DOWN].setSize(sf::Vector2u(21, 16));
	m_buttons[M_VOL_UP].setSize(sf::Vector2u(22, 15));
	m_buttons[M_SOUND].setSize(sf::Vector2u(110, 28));

	m_buttons[M_START_BUTTON].setSize(sf::Vector2u(22, 34));
	m_buttons[M_START_BUTTON].setposition(sf::Vector2f(((float)WINDOW_WIDTH / 2) - 50, ((float)WINDOW_HEIGHT / 2) + 110));
	m_buttons[M_EXIT_BUTTON].setSize(sf::Vector2u(24,23));
	m_buttons[M_EXIT_BUTTON].setposition(sf::Vector2f(m_buttons[M_START_BUTTON].getLocation().x, (m_buttons[M_START_BUTTON].getLocation().y + 110)));
	m_background.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
}

