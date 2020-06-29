#include "Board.h"
#include <vector>

using boardObjects = std::vector<ObjInfo>;// changed

Board::Board(const boardObjects& objects, b2World& world)
	:m_background(sf::Vector2f(BOARD_W, BOARD_H))
{
	setBoard(objects, world);
	m_background.setPosition(sf::Vector2f(8, 8));//fix constants
	m_background.setFillColor(sf::Color(18, 160, 159));
}

void Board::setBoard(const boardObjects& objects, b2World& world)
{
	for (auto i = 0; i < objects.size(); i++)
		m_objects.push_back(ObjFactory::create(objects[i], UNMOVABLE, world));

}

GameObj* Board::getObjWithId(const int obj)
{
	for (auto& i : m_objects)
	{
		if (i->getID() == obj)
			return i.get();
	}
}

void Board::draw(sf::RenderWindow& window, bool running)
{
	window.draw(m_background);
	if (running)
		updateImgLocs();

	for (auto& obj : m_objects)
		obj->draw(window);

	m_connections.draw(window);
}

void Board::updateImgLocs()
{
	for (auto& obj : m_objects)
		obj->updateLoc();

	m_connections.checkConnections();
}

bool Board::tryToAdd(std::shared_ptr<GameObj> current, Type_t selected) //fix take selected if non used
{
	if (current && !collides(*current.get()))
	{
		current->setInitialLoc();
		m_objects.push_back(current);
		return true;
	}
	return false;
}


bool Board::collides(GameObj& current)
{
	for (auto& i : m_objects)
	{
		if (checkCollison((*i.get()), current) && current.getID() != i->getID())
		{
			return true;
		}
	}
	return false;
}

bool Board::checkCollison(GameObj& obj2, GameObj& obj1)
{
	if(obj1.pixelPerfectColides(obj2))
		return true;

	return false;
}

std::shared_ptr<GameObj> Board::handleClick(sf::Vector2f mouseLoc, Type_t& selected)
{
	std::shared_ptr<GameObj> obj = nullptr;
	Resizable* resizableObj = nullptr;
	for (auto i = 0; i < m_objects.size(); i++)
	{
		if (m_objects[i]->mouseOnMe(mouseLoc) && m_objects[i]->isMovable())
		{
			Type_t clicked = m_objects[i]->handleClick(mouseLoc);
			if (clicked == rotateButton || clicked == resizeButton) //means it resized or rotated
			{
				resizableObj = static_cast <Resizable*> (m_objects[i].get());
				if (collides(*resizableObj))
					resizableObj->fixLastChange(clicked);
			}

			else if (clicked == connectButton)
			{
				if (Connectable* connectable = isConnectedAndConnectable(m_objects[i].get()))
				{
					selected = belt;
					m_connections.unplug(connectable);
				}
				obj = m_objects[i];
			}

			else
			{
				obj = m_objects[i];
				m_objects.erase(m_objects.begin() + i);
			}
			break;
		}
	}
	return obj;
}

std::shared_ptr<GameObj> Board::findConnectable(sf::Vector2f mouseLoc)
{

	for (auto i = 0; i < m_objects.size(); i++)
	{
		if (connectButton == m_objects[i]->handleClick(mouseLoc))
			return m_objects[i];
	}
	return nullptr;
}

void Board::resetObjectsPositions()
{
	for (auto& obj : m_objects)
		obj->backToStartingPlace();
}

bool Board::isItemInLoc(conditionToWinLoc cond) const
{
	sf::RectangleShape rect(cond.second.first);
	rect.setPosition(cond.second.second);

	for (auto& obj : m_objects)
		if (obj->getID() == cond.first)
			if (obj->getGlobalBounds().intersects(rect.getGlobalBounds()))
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

void Board::checkMouseOver(sf::Vector2f loc, std::shared_ptr<GameObj>  mouseImg)
{
	bool paintRed = false;

	for (auto& obj : m_objects)
	{
		if (mouseImg && checkCollison(*obj.get(), *mouseImg.get()))
			paintRed = true;
			
		if (obj->mouseOnMe(loc))
		{
			if (obj->isMovable())
			{
				obj->setMouse(true);
				setEveryoneElseFalse(obj->getID());
			}

		}
	}
	if(mouseImg)
	{
		if (paintRed)
			mouseImg->setColor(sf::Color::Red);
		else
		{
			mouseImg->setColor(sf::Color::White);
		}
	}
	

}

void Board::setEveryoneElseFalse(int except)
{
	for (auto& obj : m_objects)
		if (obj->getID() != except)
			obj->setMouse(false);
}

bool Board::clickedOnMe(sf::Vector2f loc) const
{
	if (m_background.getGlobalBounds().contains(loc))
		return true;

	return false;
}


void Board::drawTinyBoard(sf::RenderTexture& tinyBoard) const
{
	tinyBoard.clear(sf::Color(18, 160, 159));

	for (auto& obj : m_objects)
		obj->drawSmall(tinyBoard);

	tinyBoard.display();
}

bool Board::tryConnecting(sf::Vector2f mouseLoc)
{
	std::shared_ptr<GameObj> obj = findConnectable(mouseLoc);

	if (obj.get() != nullptr)//fix
		return (m_connections.tryConnecting(obj));

	m_connections.reset();
	return false;
}

bool Board::doneConnecting()
{
	return m_connections.doneConnecting();
}


void Board::setMousePos(sf::Vector2f mouseLoc, std::shared_ptr<GameObj> mouseImg)
{
	checkMouseOver(mouseLoc, mouseImg);

	m_connections.setMousePos(mouseLoc);
}

