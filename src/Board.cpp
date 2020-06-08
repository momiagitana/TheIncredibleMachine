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

	InitializeData();

	int objWidth = WINDOW_WIDTH / m_cols;
	int objHeight = (WINDOW_HEIGHT - TOOLBAR_SPACE) / m_rows;

	m_levelBackground.setTexture(gameTextures[O_LEVEL_BACKROUND]);
	m_levelBackground.scale((WINDOW_WIDTH / m_levelBackground.getGlobalBounds().width), (WINDOW_HEIGHT / m_levelBackground.getGlobalBounds().height));

	/*for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			c = level.getCell(i, j);
			switch (c)
			{
			case C_DIGGER:
			{
				m_digger = Digger(&gameTextures[O_DIGGER], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth - 5, (float)objHeight - 5));
				m_digger.setStoneAllowed(stons);
				break;
			}
			
			case C_STONE:
			{
				m_noneMoveObjects.emplace_back(std::make_unique<Stone>(&gameTextures[O_STONE], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth - 3, (float)objHeight - 3)));
				break;
			}
			default:
				break;
			}
		}
	}*/

}


void Board::drowBoard(sf::RenderWindow& window)
{
	window.draw(m_levelBackground);

	
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



