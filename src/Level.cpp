#include "Level.h"


Level::Level()
{

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