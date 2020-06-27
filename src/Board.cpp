#include "Board.h"
#include <vector>

using boardObjects = std::vector<ObjInfo>;// changed

Board::Board(const boardObjects& objects, b2World& world)
	:m_background(sf::Vector2f(BOARD_W, BOARD_H))
 {
	setBoard(objects, world);
	m_background.setPosition(sf::Vector2f(8,8));//fix constants
	m_background.setFillColor(sf::Color(18,160,159));
 }

void Board::setBoard(const boardObjects& objects, b2World& world)
{
	for (auto i = 0; i <objects.size(); i++)
		m_objects.push_back(ObjFactory::create(objects[i],UNMOVABLE,world));

}


  //zalman muti------------------
// void Board::testCollison(b2World& world )
// {
// 	GameObj* current = new BasketBall(sf::Vector2f(20,30),MOVABLE,world);
// 	m_objects.push_back(std::unique_ptr<GameObj>(current));

// 	for(auto& i : m_objects)
// 	{
// 		m_collision.processCollision(*current,*i.get());

// 	}

// }

// bool Board::collision(GameObj& one, GameObj& two)
// {
// 	return one.getGlobalBounds().intersects(two.getGlobalBounds());
// }


void Board::draw(sf::RenderWindow& window, bool running)

{
	window.draw(m_background);
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


  //zalman muti------------------
// 		if(current && !collides(*current))
// 		{
// 			m_objects.push_back(std::unique_ptr<GameObj>(current));
// 			return true;
// 		}
// 		else  
// 		{
// 			delete current;
// 		}
		


bool Board::tryToAdd(std::shared_ptr<GameObj> current, Type_t selected) //fix take selected if non used
{
	if(current && !collides(*current.get()))
	{
		current->setInitialLoc();
		m_objects.push_back(current);
		return true;
	}
	return false;
}


bool Board::collides(GameObj& current)
{
	for(auto& i : m_objects)
	{
		if(checkCollison((*i.get()), current) && current.getID() != i->getID())
		{
			return true;
		}
	}
	return false;

}


bool Board::checkCollison(GameObj& obj2, GameObj& obj1)
{

	if(obj1.getGlobalBounds().intersects(obj2.getGlobalBounds()))
		return true;

	return false;
}

std::shared_ptr<GameObj> Board::handleClick(sf::Vector2f mouseLoc)
{
	std::shared_ptr<GameObj> obj = nullptr;
	Resizable *resizableObj = nullptr;
	for (auto i = 0; i < m_objects.size(); i++)
	{	

		Type_t clicked = m_objects[i]->mouseOnMe(mouseLoc);
		if (m_objects[i]->isMovable() && clicked != none)
		{

			if (clicked == rotateButton || clicked == resizeButton) //means it resized or rotated
			{
				resizableObj = static_cast <Resizable*> (m_objects[i].get());
				if (collides(*resizableObj))
					resizableObj->fixLastChange(clicked);
			}
			
			else if (clicked == engineConectButton)
				obj = m_objects[i];


			else
			{
				obj = m_objects[i];
				m_objects.erase(m_objects.begin()+i);
			}
			break;
		}
	}
	return obj;
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

bool Board::clickedOnMe(sf::Vector2f loc) const
{
	if (m_background.getGlobalBounds().contains(loc))
		return true;
	
	return false;
}


void Board::drawTinyBoard (sf::RenderTexture& tinyBoard) const
{
	tinyBoard.clear(sf::Color(18,160,159));

	for(auto &obj : m_objects)
		obj->drawSmall(tinyBoard);	

   tinyBoard.display();
}

bool Board::tryConecting(sf::Vector2f mouseLoc)
{
	std::shared_ptr<GameObj> obj = handleClick(mouseLoc);

	if (obj.get() != nullptr)//fix
		return (m_conections.tryConecting(obj));
	
	return false;
}