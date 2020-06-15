#include "LevelController.h"

#include <iostream>

LevelController::LevelController(const Level& lvl, b2World& world, sf::RenderWindow& win)
	:m_board(lvl, world), m_window(win), m_toolbar(lvl)//ask yechezkel if better to send the vector
{
}

void LevelController::run()
{
	
    while (m_window.isOpen())
    {
		drawAll();

		sf::Event event;

		while (m_window.pollEvent(event) && !levelStatus())// level status might have to be on the outer while
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:

                auto mouseLoc = m_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

				if (clickOnToolbar(mouseLoc))
				{
					m_selected = m_toolbar.toolbarclick(mouseLoc);
					updateMouseImg(mouseLoc);

					if(m_selected == play)//needs to be inside the if ontop??
					{
						if(m_board.tryRunning())//apply gravitiy check if game was won
							setlevelStatus(false);//leave the while and next level
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
							m_toolbar.decreaseObjCount(m_selected);
							m_selected = none;
						}
					}
					if(m_selected == none)
						m_selected = m_board.handleClick(mouseLoc);//tries to grabb and object flip it or delete it..
				}
				break;

			case sf::Event::MouseMoved:
				auto mouseLocation = sf::Mouse::getPosition(m_window);
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
	return m_toolbar.clickedOnMe(mouseLoc);
}

bool LevelController::clickOnBoard(sf::Vector2f mouseLoc)
{
	return m_board.clickedOnMe(mouseLoc);
}

bool LevelController::levelStatus()
{
	return m_notFinished;
}

bool LevelController::setlevelStatus(const bool status)
{
	m_notFinished = status;
}

void LevelController::drawAll()
{
	m_window.clear(sf::Color::Transparent);

	m_board.draw(m_window);
	m_toolbar.draw(m_window);
	m_currObj.draw(m_window);

    m_window.display();

}