#include "LevelController.h"

#include <iostream>

LevelController::LevelController(const Level& lvl, b2World& world, sf::RenderWindow& win)
	:m_board(lvl, world) m_window(win) m_toolbar(lvl)//ask yechezkel if better to send the vector
{
}

void LevelController::run()
{
	
    while (m_window.isOpen())
    {
		m_window.clear(sf::Color::Transparent);

		m_board.draw(m_window);
		m_toolbar.draw(m_window);

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

                auto mouseLoc = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
				if (clickOnToolbar(mouseLoc))
					;//m_selection = m_toolbar.handleClick(moseLoc);
				
				// if(m_selected == play)
				// 		if(tryRunning())//apply gravitiy check if game was won
				// 			break;leave the while and next level
				// 	else
				// 		board.resetObjectsPossitions()//from before gravity


				if (clickOnBoard(mouseLoc))
					if(m_selected != none)
						if(m_board.tryToAdd(mouseLoc, m_selected)) //returns true if managed added obj
						{
							m_toolbar.delete(m_selected);
							m_selected = none;
						}
					if(m_selected == none)
						m_selected == m_board.handleClick(mouseLoc);//tries to grabb and object flip it or delete it..
						
			}
        }

    }


}