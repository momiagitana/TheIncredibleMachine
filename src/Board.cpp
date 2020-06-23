#include "Board.h"
#include <vector>

Board::Board(const Level& lvl, b2World& world)
 {
	setBoard(lvl, world);
 }

void Board::setBoard(const Level& level, b2World& world)
{
	for (auto i = 0; i < level.getBoardSize(); i++)//{
		m_objects.push_back(ObjFactory::create(level.getFromBoard(i).first,level.getFromBoard(i).second,UNMOVABLE,world));
	// 	switch (level.getFromBoard(i).first)
	// 	{
	// 		case balloon:
	// 			m_objects.push_back(ObjFactory::create(balloon,level.getFromBoard(i).second,UNMOVABLE,world));
	// 			break;
	// 		case basketBall:
	// 			m_objects.push_back(ObjFactory::create(basketBall,level.getFromBoard(i).second,UNMOVABLE,world));
	// 			break;
	// 		case baseBall:
	// 			m_objects.push_back(ObjFactory::create(baseBall,level.getFromBoard(i).second,UNMOVABLE,world));
	// 			break;
	// 		case brickWall:
	// 			m_objects.push_back(ObjFactory::create(brickWall,level.getFromBoard(i).second,UNMOVABLE,world));
	// 			break;

	// 	}
	// }
}


void Board::draw(sf::RenderWindow& window, bool running)
{
	if (running)
		updateImgLocs();

	for(auto &obj : m_objects)
		obj->draw(window);
}

void Board::updateImgLocs()
{
	for(auto &obj : m_objects)
		obj->updateLoc();
}


bool Board::tryToAdd(sf::Vector2f mouseLoc, Type_t currObj, b2World& world )
{
	std::unique_ptr<GameObj> current = ObjFactory::create(currObj,mouseLoc,UNMOVABLE,world);
	// GameObj* current = nullptr;
	// switch (currObj)
	// 	{
	// 		case balloon:
	// 			current = new Balloon(mouseLoc,MOVABLE,world);
	// 			break;
	// 		case basketBall:
	// 			current = new BasketBall(mouseLoc,MOVABLE,world);
	// 			break;
	// 		case baseBall:
	// 			current = new BaseBall(mouseLoc,MOVABLE,world);
	// 			break;
	// 		 case brickWall:
	// 		 	current = new BrickWall(mouseLoc,MOVABLE,world);
	// 		 	break;
		
	// 	}

		if(current && !collides(current.get()))
		{
			m_objects.push_back(std::move(current));
			return true;
		}
		// 	if(current && !collides(current))
		// {
		// 	m_objects.push_back(std::unique_ptr<GameObj>(current));
		// 	return true;
		// }
		// else
		// {
		// 	delete current;
		// }
		
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
	Resizable *resizableObj = nullptr;
	for (auto i = 0; i<m_objects.size(); i++)
	{	
		if (m_objects[i]->isMovable())
		{

			if (typeid(*(m_objects[i].get())) == typeid(BrickWall))
			{
				Type_t whatHappen = none;
				resizableObj = static_cast <Resizable*> (m_objects[i].get());
				if(resizableObj->clickedOnMe(mouseLoc, whatHappen))
				{
					type = m_objects[i]->getType();
					m_objects.erase(m_objects.begin()+i);
				}
				else if (whatHappen != none) //means it resized or rotated
				{
					if (collides(resizableObj))
					{
						resizableObj->fixLastChange(whatHappen);
					}
				}

				
			}			
				
			else if(m_objects[i]->mouseOnMe(mouseLoc))
			{
				type = m_objects[i]->getType();
				m_objects.erase(m_objects.begin()+i);
			}

		}
	}
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


void Board::checkMouseOver(sf::Vector2f loc)
{
	for(auto& obj : m_objects)
	{
		if(obj->mouseOnMe(loc))
		{
			if(obj->isMovable())
			{
				obj->setMouse(true);
				setEveryoneElseFalse(obj->getID());
			}
		}
	}
}

void Board::setEveryoneElseFalse(int except)
{
	for (auto &obj : m_objects)
		if(obj->getID() != except)
			obj->setMouse(false);
}