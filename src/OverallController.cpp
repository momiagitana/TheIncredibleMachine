#include "OverallController.h"
#include <iostream>
#include "ResourceManager.h"



OverallController::OverallController(b2World& world) 
	:m_world(world), m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "IncredibleMachine", sf::Style::Default)
{
	FileHandler file(ResourceManager::instance().getLevelPath());
	m_levels = file.readLevels();
	m_window.setFramerateLimit(60);

}

void OverallController::run()
{
	
	while (m_window.isOpen()) {
		m_menu.runStart(m_window);

		if (m_menu.shouldStartplaying())
		{
			// ---------- test --------
			auto levelcontroler = LevelController(m_levels[0], m_world, m_window);
			levelcontroler.run();
			// -------------------------
		}
		else
		{
			m_window.close();
		}
	}
}
