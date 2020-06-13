#include "OverallController.h"

#include <iostream>
#include "ResourceManager.h"

using std::cout;


OverallController::OverallController() :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine")
{

}

void OverallController::run()
{

	while (m_window.isOpen())
	{
		auto pos = sf::Mouse::getPosition(m_window);

		sf::Event e;

		m_window.clear();

		m_window.display();

		if (m_window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}
	}
}






//--------toolbar managment david

	//Toolbar t(WINDOW_WIDTH, WINDOW_HEIGHT);

	// t.setLevelObjects( figure::Basketball,2,
	// 				   figure::Bowling,6,
	// 					figure::Engine,18);
			// case sf::Event::MouseButtonPressed:
			// {
			// 	const auto location = m_window.mapPixelToCoords({ e.mouseButton.x, e.mouseButton.y });
			// 	switch (e.key.code)
			// 	{
			// 	case sf::Mouse::Left:
			// 		figure temp = t.toolbarclick(location);
			// 		t.light(location);
			// 		if (temp == figure::Basketball)
			// 		{
			// 			cout << "BasketBall\n";
			// 		}
			// 		if (temp == figure::Bowling)
			// 		{
			// 			cout << "BowlingBall\n";
			// 		}
			// 		if (temp == figure::Arrows)
			// 		{
			// 			cout << "Arows\n";
			// 		}
			// 		if (temp == figure::Engine)
			// 		{
			// 			cout << "Engine\n";
			// 		}
			// 	}
			// 	break;
			// }

			// case sf::Event::MouseButtonReleased:
			// {
			// 	t.unlight(sf::Vector2f(pos.x, pos.y));
			// 	break;
			// }