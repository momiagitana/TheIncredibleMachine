#include "LevelController.h"
#include "ResourceManager.h"
#include <iostream>

LevelController::LevelController(const Level& lvl, b2World& world, sf::RenderWindow& win)
	:m_board(lvl, world), m_window(win), m_world(world), m_toolbar(lvl.getToolbarObjs()),
	m_locConditons(lvl.getLocConditions()), m_actConditions(lvl.getActConditions()),
	m_mouseImg(sf::Vector2f(-100.f, -100.f), baseBall)//fix
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
				auto mouseLoc = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

				if (clickOnToolbar(mouseLoc))
				{
					if(m_selected == none)
					{
						setSelected(m_toolbar.handleClick(mouseLoc),mouseLoc);
						if (m_selected == play)//needs to be inside the if ontop??
						{
							if (tryRunning())//apply gravitiy check if game was won
								m_finished = true;//leave the while and next level
							else
								m_board.resetObjectsPositions();//from before gravity
							setSelected(none, mouseLoc);
						}
					}

					else
					{
						m_toolbar.addOrIncrease(m_selected);
						setSelected(none, mouseLoc);
					}
				}

				else if (clickOnBoard(mouseLoc))
				{
					if (m_selected != none)
					{
						if(m_board.tryToAdd(mouseLoc, m_selected, m_world)) //returns true if managed added obj
						{
							setSelected(none, mouseLoc);
						}
					}
					else //if(m_selected == none)
						setSelected(m_board.handleClick(mouseLoc), mouseLoc);//tries to grabb and object flip it or delete it..
				}
				break;
			}
			case sf::Event::MouseMoved:
				auto mouseLoc = m_window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
				updateMouseLoc(mouseLoc);
				break;
			}

        }
    }
	
	// while(replaySolution())
	// 	tryRunning();

}

void LevelController::setSelected(Type_t type, const sf::Vector2f loc)
{
	m_selected = type;
	updateMouseImg (loc);
}

void LevelController::updateMouseImg(const sf::Vector2f loc)
{
	m_mouseImg = BaseImg(loc, Type_t(m_selected+100));//fix
}

void LevelController::updateMouseLoc(const sf::Vector2f loc)
{
	m_mouseImg.setPosition(loc);

	m_board.checkMouseOver(loc);
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
	m_window.clear(sf::Color(18, 160, 159));

	m_board.draw(m_window, false);//fix RUNNING
	m_toolbar.draw(m_window);
	
	if (m_selected < play)
		m_mouseImg.draw(m_window);

	m_window.display();
}

bool LevelController::tryRunning()
{
	m_board.hideObjButtons();
	while (m_window.isOpen())
	{
		if (checkIfLevelFinished()) //we check every 10 step
			return true;

		// Update window
		m_window.clear(sf::Color(18, 160, 159));

		// Update world Box2D
		m_world.Step(TIMESTEP, VELITER, POSITER);

		m_board.draw(m_window, true);//fix
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