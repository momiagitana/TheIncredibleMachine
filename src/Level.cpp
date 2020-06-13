#include "Level.h"


Level::Level()
{
	m_toolbar.push_back(std::pair(basketBall,3));
	m_toolbar.push_back(std::pair(baseBall,2));

	m_initial.push_back(std::pair(baseBall,sf::Vector2f(100.f,100.f)));
	m_initial.push_back(std::pair(baseBall,sf::Vector2f(150.f,150.f)));
	m_initial.push_back(std::pair(baseBall,sf::Vector2f(200.f,200.f)));
	m_initial.push_back(std::pair(conveyor,sf::Vector2f(100.f,300.f)));

}

void Level::addBoardObj(GameObject_t obj, sf::Vector2f loc)
{
	m_initial.push_back(std::pair(obj,loc));
}

void Level::addToolbarObj (GameObject_t obj, int amount)
{
	m_toolbar.push_back(std::pair(obj, amount));
}
