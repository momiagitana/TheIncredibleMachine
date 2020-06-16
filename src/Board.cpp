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
			// case bowlingBall:
			// case conveyor:

		}
	}
}


void Board::draw(sf::RenderWindow& window)
{
	for(auto &obj : m_objects)
		obj->draw(window);
}


// bool Board::levelFinished()
// {

// 	return false;
// }

// void Board::MoveObjects(sf::Time deltaTime)
// {

// }

bool Board::tryToadd(sf::Vector2f mouseLoc, GameObject_t currObj)
{
	return true;
}

GameObject_t Board::handleClick(sf::Vector2f mouseLoc)
{
	return none;
}

void Board::resetObjectsPositions()
{
	for (auto &obj : m_objects)
		obj->setInitialLoc();
}


