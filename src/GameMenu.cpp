#include "GameMenu.h"

GameMenu::GameMenu() {}

void GameMenu::settexturs( sf::RenderWindow& window)
{
	for (int i = background; i < none; i++)
	{
		sf::Sprite sprite;
		auto text = ResourceManager::instance().getTexture((GameObject_t(i)));
		sprite.setTexture(*text);
		m_sprits.push_back(sprite);
	}
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
				if (m_sprits[M_EXIT_BUTTON].getGlobalBounds().contains(location))
				{
					
					m_StartPlaying = false;
					return;
				}
				if (m_sprits[M_START_BUTTON].getGlobalBounds().contains(location))
				{
					
					m_StartPlaying = true;
					return;
				}

				break;
			}
			case sf::Event::MouseMoved:
				// Save the position of the mouse:
				auto mousePos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				if (m_sprits[M_START_BUTTON].getGlobalBounds().contains(mousePos))
				{
					m_sprits[M_START_BUTTON].setColor(sf::Color(255, 255, 255, 128));
				}
				else
				{
					m_sprits[M_START_BUTTON].setColor(sf::Color::White);
				}
				if (m_sprits[M_EXIT_BUTTON].getGlobalBounds().contains(mousePos))
				{
					m_sprits[M_EXIT_BUTTON].setColor(sf::Color(255, 255, 255, 128));
				}
				else
				{
					m_sprits[M_EXIT_BUTTON].setColor(sf::Color::White);
				}

			}
		}
	}
}

void GameMenu::draw(sf::RenderWindow& window)
{
	window.draw(m_sprits[M_BACKGROUND]);
	window.draw(m_sprits[M_START_BUTTON]);
	window.draw(m_sprits[M_EXIT_BUTTON]);
	window.draw(m_text);
}

bool GameMenu::shouldStartplaying()const
{
	return m_StartPlaying;
}

void GameMenu::setSprits(sf::RenderWindow& window)
{
	m_sprits[M_START_BUTTON].setScale((100) / m_sprits[M_START_BUTTON].getLocalBounds().width, (80) / m_sprits[M_START_BUTTON].getLocalBounds().height);
	m_sprits[M_START_BUTTON].setPosition(sf::Vector2f(((float)WINDOW_WIDTH / 2) -50, ((float)WINDOW_HEIGHT / 2) + 110));
	m_sprits[M_EXIT_BUTTON].setScale((100) / m_sprits[M_EXIT_BUTTON].getLocalBounds().width, (80) / m_sprits[M_EXIT_BUTTON].getLocalBounds().height);
	m_sprits[M_EXIT_BUTTON].setPosition(sf::Vector2f(m_sprits[M_START_BUTTON].getPosition().x, (m_sprits[M_START_BUTTON].getPosition().y + 110)));
	m_sprits[M_BACKGROUND].scale((WINDOW_WIDTH / m_sprits[M_BACKGROUND].getGlobalBounds().width), (WINDOW_HEIGHT / m_sprits[M_BACKGROUND].getGlobalBounds().height));
}

