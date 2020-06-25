#include "LevelController.h"
#include "ResourceManager.h"
#include <iostream>

LevelController::LevelController(const Level& lvl, b2World& world, sf::RenderWindow& win)
	:m_board(lvl.getBoardObjs(), world), m_window(win), m_world(world), m_toolbar(lvl.getToolbarObjs()),
	m_locConditons(lvl.getLocConditions()), m_actConditions(lvl.getActConditions()),
	m_mouseImg(sf::Vector2f(-100.f, -100.f),baseBall),
  m_frame (sf::Vector2f(FRAME_X, FRAME_Y), frame)

{
}

bool LevelController::run()
{
	while (m_window.isOpen() && !m_finished)
	{
		drawAll(false);//NOT_RUNNING fix

		sf::Event event;

		while (m_window.pollEvent(event) && !m_finished)// fix 
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:
			{
				if(event.mouseButton.button == sf::Mouse::Button::Right)
					return false; //fix
					
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
							//setSelected(none, mouseLoc);
							clearMouse(none, mouseLoc);

						}
					}
					else
					{
						m_toolbar.addOrIncrease(m_selected);
						//setSelected(none, mouseLoc);
						clearMouse(none, mouseLoc);
					}
				}

				else if (clickOnBoard(mouseLoc))
				{
					if (m_selected != none)
					{
						if(m_board.tryToAdd(m_mouseObj)) //returns true if managed added obj
						{
							clearMouse(none, mouseLoc);
						}
					}
					else //if(m_selected == none)
						setSelected(m_board.handleClick(mouseLoc), mouseLoc);//tries to grabb and object flip it or delete it..
				}
				break;
			}
			case sf::Event::MouseMoved:
				auto mouseLoc = m_window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
				whereAmI(mouseLoc);
				updateMouseLoc(mouseLoc);
			
				break;

				
			}
        }
    }


	m_board.saveLevelToFile();

	// while(replaySolution())
	// 	tryRunning();
  return m_finished;

}

void LevelController::whereAmI(sf::Vector2f mouseLoc)
{
	if(clickOnToolbar(mouseLoc)) //maybe use set funcs and check if need both ifs
		m_mouseOnToolBr = true;
	if(clickOnBoard(mouseLoc))
		m_mouseOnToolBr = false;
}

void LevelController::setSelected(Type_t type, const sf::Vector2f loc)
{
	m_selected = type;
	updateMouseImg (loc);
}

void LevelController::clearMouse(Type_t type, const sf::Vector2f loc)
{
	m_selected = type;
	//m_mouseImg = BaseImg(loc, Type_t(m_selected+100));//might have some code reuse here need to check
	m_mouseObj = nullptr;
}

void LevelController::updateMouseImg(const sf::Vector2f loc)
{
	m_mouseImg = BaseImg(loc, Type_t(m_selected+100));//fix
	m_mouseObj = ObjFactory::create(m_selected,loc,MOVABLE,m_world);
}

void LevelController::updateMouseLoc(const sf::Vector2f loc)
{
	m_mouseImg.setPosition(loc);
	
	if(m_mouseObj)
		m_mouseObj->setPosition(loc);

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

void LevelController::drawAll(bool running)
{
	m_window.clear(sf::Color(18, 160, 159));

	m_board.draw(m_window, running);//fix RUNNING

	m_frame.draw(m_window);
	m_toolbar.draw(m_window);
	
	if (m_selected < play)
	{
		if(m_mouseOnToolBr)
		{
			m_mouseImg.draw(m_window);
		}
		else if(m_mouseObj && !m_mouseOnToolBr)
		{
			m_mouseObj->draw(m_window);
		}	
	}

	m_window.display();
}

bool LevelController::replaySolution()
{
	BaseImg nextLevelMesseage(sf::Vector2f(400,300),Type_t::msgRublic);
	Button replayLevelRexuest(sf::Vector2f(350,350),Type_t::msgRepley);
	Button advanceRequest(sf::Vector2f(460,350),Type_t::msgAdvance);
	
	sf::Event evnt;

	nextLevelMesseage.draw(m_window);
	advanceRequest.draw(m_window);
	replayLevelRexuest.draw(m_window);
	m_window.display();

	while (m_window.isOpen())
	{

		while (m_window.waitEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;

			case sf::Event::MouseButtonReleased:
				auto mouseLoc = m_window.mapPixelToCoords({ evnt.mouseButton.x, evnt.mouseButton.y });

				if (advanceRequest.mouseOnMe(mouseLoc))
				{
					return false;
				}
				if (replayLevelRexuest.mouseOnMe(mouseLoc))
				{
					return true;
				}
				break;
			}
		}
	}
}

bool LevelController::tryRunning()
{
	m_board.hideObjButtons();
	while (m_window.isOpen())
	{
		if (checkIfLevelFinished())
			return true;

		m_world.Step(TIMESTEP, VELITER, POSITER);

		drawAll(true);//fix RUNNING

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