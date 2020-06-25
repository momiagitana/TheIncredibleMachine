#include "Board.h"
#include <vector>

Board::Board(const Level& lvl, b2World& world)
 {
	setBoard(lvl, world);
 }

void Board::setBoard(const Level& level, b2World& world)
{
	for (auto i = 0; i < level.getBoardSize(); i++)
		m_objects.push_back(ObjFactory::create(level.getFromBoard(i).first,
											   level.getFromBoard(i).second,
											   UNMOVABLE,world));
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

bool Board::tryToAdd(std::shared_ptr<GameObj> current)
{
	if(current && !collides(current.get()))//probably can remove the check if current is null
	{
		current->setInitialLoc();
		m_objects.push_back(current);
		return true;
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
	Resizable *resizableObj = nullptr;
	for (auto i = 0; i < m_objects.size(); i++)
	{	
		if (m_objects[i]->isMovable())
		{

			if (isResizable(m_objects[i].get()))
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
		obj->backToStartingPlace();
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

bool Board::isResizable(GameObj* curr) const
{
	if(typeid(*(curr)) == typeid(BrickWall))
		return true;
	if(typeid(*(curr)) == typeid(Conveyor))
		return true;

	return false;

}