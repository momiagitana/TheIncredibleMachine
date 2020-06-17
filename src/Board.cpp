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

bool Board::tryToadd(sf::Vector2f mouseLoc, GameObject_t currObj, b2World& world )
{
	//if(currObj != chain)??
	GameObj* current;

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
			// case bowlingBall:
			// 	current = new BowlingBall(mouseLoc,MOVABLE,world);
			// 	break;

		
		}

		if(!collided(current))
		{
			m_objects.push_back(std::unique_ptr<GameObj>(current));
			return true;
		}
		else  
		{
			delete current;
		}
		
	// else
	// {
	// 	//addChain();
	// }
	
	return false;
}


bool Board::collided(GameObj* current)
{
	for(auto& i : m_objects)
	{
		if(checkCollison(i.get(),current))
		{
			return true;
		}
	}
		return false;
}


bool Board::checkCollison(GameObj* obj2, GameObj* obj1)
{
	if(obj1->getGlobalBounds().intersects(obj2->getGlobalBounds()))
	{
		return true;
	}

	return false;
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


