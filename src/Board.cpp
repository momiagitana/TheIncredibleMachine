#include "Board.h"
#include <experimental/vector>

Board::Board() {}

void Board::setBoard(const Level& level, const std::vector<sf::Texture>& gameTextures)
{
	char c;
	m_cols = level.getCols();
	m_rows = level.getRows();
	m_time = level.getTime();
	int stons = level.getStones();

	//InitializeData();

	int objWidth = WINDOW_WIDTH / m_cols;
	int objHeight = (WINDOW_HEIGHT - TOOLBAR_SPACE) / m_rows;

	
}


void Board::drowBoard(sf::RenderWindow& window)
{
}


int Board::getTime()const
{
	return m_time;
}

void Board::setTime(int levelTime)
{
	m_time = levelTime;
}

void Board::handleCollisions(BaseObject& baseobject)
{

	/*for (auto& monsters : m_monsters)
	{
		if (baseobject.checkCollision(monsters->getGlobalBounds()))
		{
			baseobject.collide(*monsters);
		}
	}*/
}

bool Board::levelFinished()
{
	/*if ( finished)
		return true;*/
	return false;
}

void Board::MoveObjects(sf::Time deltaTime)
{

}



