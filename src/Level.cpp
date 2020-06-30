#include "Level.h"


Level::Level()
{
}

Level::Level(bool buildLevel)
{
	for (int i = balloon; i < play; ++i)
	{
		addToolbarObj(Type_t(i), -1);
	}
	addCondLoc(0, sf::Vector2f(0,0), sf::Vector2f(0,0));//fix
}

void Level::addBoardObj(ObjInfo obj)
{
	m_initial.push_back(obj);
}

void Level::addToolbarObj (Type_t obj, int amount)
{
	m_toolbar.push_back(std::pair(obj, amount));
}

void Level::addCondLoc (int id, sf::Vector2f loc, sf::Vector2f size)
{
	m_locConditons.push_back(std::pair(id,std::pair(loc, size)));
}

void Level::addCondAct (int id)
{
	m_actConditions.push_back(id);
}

void Level::addName(const std::string& name)
{
	m_name = name;
}

void Level::addLevelGoal(const std::string& levelGoal)
{
	m_levelGoal = levelGoal;
}
