#include "LevelController.h"
#include "ResourceManager.h"
#include <iostream>

LevelController::LevelController(const Level& lvl, b2World& world, sf::RenderWindow& win)
	:m_board(lvl, world), m_window(win), m_world(world), m_toolbar(lvl.getToolbarObjs()),
	m_locConditons(lvl.getLocConditions()), m_actConditions(lvl.getActConditions()),
	m_mouseImg(sf::Vector2f(-100.f, -100.f),ResourceManager::instance().getTexture(baseBall))//ask yechezkel if better to send the vector
{
}

void LevelController::run()
{
	while (m_window.isOpen() && !m_finished)
	{
		drawAll();

		sf::Event event;

		while (m_window.pollEvent(event) && !m_finished)// level status might have to be on the outer while
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:
			{
				// if (event.mouseButton.button == sf::Mouse::Right)
				// {
				// 	if (tryRunning())//apply gravitiy check if game was won
				// 		m_finished = true;//leave the while and next level
				// 	else
				// 		m_board.resetObjectsPositions();//from before gravity
				// }

				auto mouseLoc = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (clickOnToolbar(mouseLoc))
				{
					m_selected = m_toolbar.handelclick(mouseLoc);
					updateMouseImg(mouseLoc);
					if (m_selected == play)//needs to be inside the if ontop??
					{
						if (tryRunning())//apply gravitiy check if game was won
							m_finished = true;//leave the while and next level
						else
							m_board.resetObjectsPositions();//from before gravity
						m_selected = none;
					}
				}

				else if (clickOnBoard(mouseLoc))
				{
					
					if (m_selected != none)
					{
						if(m_board.tryToadd(mouseLoc, m_selected, m_world)) //returns true if managed added obj
						{
<<<<<<< HEAD
							
							//							m_toolbar.decreaseObjCount(m_selected);
=======
							m_toolbar.drope(m_toolbar.getCurrent_at_Hold());
							
>>>>>>> master
							m_selected = none;
							
						}
					}
					else //if(m_selected == none)
						m_selected = m_board.handleClick(mouseLoc);//tries to grabb and object flip it or delete it..
				}
				break;
			}
			case sf::Event::MouseMoved:

				auto mouseLoc = m_window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
				updateMouseImg(mouseLoc);
				updateMouseLoc(mouseLoc);
				break;
			}

        }
    }
}

void LevelController::updateMouseImg(const sf::Vector2f loc)
{
	sf::Texture *texture = ResourceManager::instance().getTexture(m_selected);
	auto size = texture->getSize();
	m_mouseImg = BaseImg(loc, texture);
}

void LevelController::updateMouseLoc(const sf::Vector2f loc)
{
	m_mouseImg.setposition(loc);
}

bool LevelController::clickOnToolbar(sf::Vector2f mouseLoc)
{
	return m_toolbar.clickedOnMe(mouseLoc);
}

bool LevelController::clickOnBoard(sf::Vector2f mouseLoc)
{
	return m_board.clickedOnMe(mouseLoc);
}

bool LevelController::levelStatus()
{
	return m_finished;
}

bool LevelController::setlevelStatus(const bool status)
{
	m_finished = status;
	return m_finished;
}

void LevelController::drawAll()
{
	m_window.clear(sf::Color::Transparent);

	m_board.draw(m_window);
	m_toolbar.draw(m_window);
	
	if (m_selected < play)
		m_mouseImg.draw(m_window);

	m_window.display();
}

bool LevelController::tryRunning()
{
	int stepCounter = 0;

	while (m_window.isOpen())
	{
		if (stepCounter == 2)//change 10 to const
		{
			if (checkIfLevelFinished()) //we check every 10 step
				return true;
			else
				stepCounter = 0;
		}
		else
			stepCounter++;

		// Update window
		m_window.clear(sf::Color::Transparent);

		// Update world Box2D
		m_world.Step(TIMESTEP, VELITER, POSITER);

		m_board.draw(m_window);
		m_toolbar.draw(m_window);

		// Render window
		m_window.display();

		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Right)
					return false;
				break;
			default:
				break;
			}
        }
    }

}

bool LevelController::checkIfLevelFinished() const
{

	for(auto i = 0; i < m_locConditons.size(); i++)
	{
		if (!m_board.isItemInLoc(m_locConditons[i]))
			return false;
	}
	return true;
}