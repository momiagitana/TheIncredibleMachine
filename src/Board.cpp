#include "Board.h"
#include <vector>

using boardObjects = std::vector<ObjInfo>;// changed

Board::Board(const boardObjects& objects, b2World& world)
 {
	setBoard(objects, world);
 }

void Board::setBoard(const boardObjects& objects, b2World& world)
{
	for (auto i = 0; i <objects.size(); i++)
		m_objects.push_back(ObjFactory::create(objects[i],UNMOVABLE,world));
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
	ObjInfo info;
	info._typ = currObj;
	info._loc = mouseLoc;

	std::unique_ptr<GameObj> current = ObjFactory::create(info,MOVABLE,world);

	if(current && !collides(current.get()))
	{
		m_objects.push_back(std::move(current));
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
	for (auto i = 0; i<m_objects.size(); i++)
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

void Board::saveLevelToFile()
{
	auto file = FileHandler(ResourceManager::instance().getLevelPath(), false);//fix SAVE
	file.saveNewLevel(getObjInfo());
}


std::vector<ObjInfo> Board::getObjInfo() const
{
	auto info = std::vector<ObjInfo>();
	for (auto& obj : m_objects)
		info.push_back(obj->getInfo());
	return info;
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

