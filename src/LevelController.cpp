#include "LevelController.h"
#include "ResourceManager.h"
#include <iostream>

LevelController::LevelController(const Level& lvl, b2World& world, sf::RenderWindow& win)
	:m_board(lvl, world), m_window(win), m_world(world), /*m_toolbar(lvl)*/ m_locConditons(lvl.getLocConditions()), m_actConditions(lvl.getActConditions()), m_currObj(sf::Vector2f(0.f,0.f), sf::Vector2f(20.f,20.f), ResourceManager::instance().getTexture(baseBall))//ask yechezkel if better to send the vector
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
				if (event.mouseButton.button == sf::Mouse::Right)
					tryRunning();

                auto mouseLoc = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

				if (clickOnToolbar(mouseLoc))
				{
					//m_selected = m_toolbar.toolbarclick(mouseLoc);
					updateMouseImg(mouseLoc);

					if(m_selected == play)//needs to be inside the if ontop??
					{
						if(tryRunning())//apply gravitiy check if game was won
							m_finished = true;//leave the while and next level
						else
							m_board.resetObjectsPossitions();//from before gravity
					}
				}
				

				if(clickOnBoard(mouseLoc))
				{
					if(m_selected != none)
					{
						if(m_board.tryToAdd(mouseLoc, m_selected)) //returns true if managed added obj
						{
							//m_toolbar.decreaseObjCount(m_selected);
							m_selected = none;
						}
					}
					if(m_selected == none)
						m_selected = m_board.handleClick(mouseLoc);//tries to grabb and object flip it or delete it..
				}
				break;
			}

			case sf::Event::MouseMoved:
				auto mouseLoc = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
				updateMouseLoc(mouseLoc);
			break;
			}
        }

    }


}


void LevelController::updateMouseImg(const sf::Vector2f loc)
{
	m_currObj = BaseImg(loc, sf::Vector2f(30.f,50.f), ResourceManager::instance().getTexture(m_selected));
}

void LevelController::updateMouseLoc(const sf::Vector2f loc)
{
	m_currObj.setLocation(loc);
}

bool LevelController::clickOnToolbar(sf::Vector2f mouseLoc)
{
	return false; //m_toolbar.clickedOnMe(mouseLoc);
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
	//m_toolbar.draw(m_window);
	m_currObj.draw(m_window);

  	m_window.display();
}

bool LevelController::tryRunning()
{
	int stepCounter = 0;

	while (m_window.isOpen())
    {
		if(stepCounter == 10)//change 10 to const
		{
			if(checkIfLevelFinished()) //we check every 10 step
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
		//m_toolbar.draw(m_window);

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

			      }
        }

    }


}