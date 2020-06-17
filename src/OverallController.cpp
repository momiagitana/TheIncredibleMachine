#include "OverallController.h"

#include <iostream>
#include "ResourceManager.h"

using std::cout;


OverallController::OverallController(const Level&level, b2World& world) 
	:m_world(world), m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine", sf::Style::Default), m_levelController(level, world, m_window)
{
	
	m_window.setFramerateLimit(60);
	// readlevels();

}

void OverallController::run()
{
	m_menu.settexturs(m_window);
	while (m_window.isOpen()) {
		m_menu.runstart(m_window);

		if (m_menu.shouldStartplaying())
		{
			m_levelController.run();
		}
		else
		{
			m_window.close();
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