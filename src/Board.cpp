#include "Board.h"
#include <vector>

Board::Board(const Level& lvl, b2World& world)
 {
	setBoard(lvl, world);
 }

void Board::setBoard(const Level& level, b2World& world)
{

	for (auto i = 0; i < level.getBoardSize(); i++)
	{
		switch (level.getFromBoard(i).first)
		{
			case balloon:
				m_objects.push_back(std::make_unique<Balloon>(level.getFromBoard(i).second, UNMOVABLE, world));
				break;
			case basketBall:
				m_objects.push_back(std::make_unique<BasketBall>(level.getFromBoard(i).second, UNMOVABLE, world));
				break;
			case baseBall:
				m_objects.push_back(std::make_unique<BaseBall>(level.getFromBoard(i).second, UNMOVABLE, world));
				break;
			case brickWall:
				m_objects.push_back(std::make_unique<BrickWall>(level.getFromBoard(i).second, UNMOVABLE, world));
				break;

		}
	}
}


void Board::draw(sf::RenderWindow& window, bool running)
{
	for(auto &obj : m_objects)
		obj->draw(window, running);
}


bool Board::tryToAdd(sf::Vector2f mouseLoc, Type_t currObj, b2World& world )
{

	GameObj* current = NULL;

	switch (currObj)
		{
			case balloon:
				current = new Balloon(mouseLoc,MOVABLE,world);
				break;
			case basketBall:
				current = new BasketBall(mouseLoc,MOVABLE,world);
				break;
			case baseBall:
				current = new BaseBall(mouseLoc,MOVABLE,world);
				break;
			 case brickWall:
			 	current = new BrickWall(mouseLoc,MOVABLE,world);
			 	break;
		
		}

		if(current && !collides(current))
		{
			m_objects.push_back(std::unique_ptr<GameObj>(current));
			return true;
		}
		else  
		{
			delete current;
		}
		
	
	return false;
}


bool Board::collides(GameObj* current)
{
	for(auto& i : m_objects)
	{
		if(checkCollison(i.get(),current) && current->getID() != i->getID())
		{
			return true;
		}
	}
		return false;
}


bool Board::checkCollison(GameObj* obj2, GameObj* obj1)
{
	if(obj1->getGlobalBounds().intersects(obj2->getGlobalBounds()))
		return true;

	return false;
}

Type_t Board::handleClick(sf::Vector2f mouseLoc)
{
	Type_t type = none;
	//BrickWall* current;
	for (auto i = 0; i<m_objects.size(); i++)
		if(m_objects[i]->getGlobalBounds().contains(mouseLoc) && m_objects[i]->isMovable())
		{
			type = m_objects[i]->getType();
			m_objects.erase(m_objects.begin()+i);
		}
		// else if (m_objects[i]->getGlobalBounds().contains(mouseLoc) && !m_objects[i]->isMovable())
		// {
		// 	current = static_cast <BrickWall*> (m_objects[i].get());
		// 	if(!current->isMovable())
		// 	{
		// 		current->shiftL();
		// 		if(collides(current))
		// 			current->shiftR();
		// 	}
		// }
	return type;
}

void Board::resetObjectsPositions()
{
	for (auto &obj : m_objects)
		obj->setInitialLoc();
}


bool Board::isItemInLoc(conditionToWinLoc cond) const
{
	sf::RectangleShape rect(cond.second.first);
	rect.setPosition(cond.second.second);

	for(auto &obj : m_objects)
		if (obj->getID() == cond.first)
			if(obj->getGlobalBounds().intersects(rect.getGlobalBounds()))
				return true;
	
	return false;
}
