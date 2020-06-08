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

	for (int i = 0; i < m_rows; i++)
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
			case C_MONSTER:
			{
				switch ((rand() % 2) + 1)
				{
				case 1:
					m_monsters.emplace_back(std::make_unique<DumbMonster>(&gameTextures[O_DUMB_MONSTER], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth - 3, (float)objHeight - 3)));
					break;
				case 2:
					m_monsters.emplace_back(std::make_unique<SmartMonster>(&gameTextures[O_SMART_MONSTER], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth - 3, (float)objHeight - 3)));
					break;
				}
				break;
			}
			case C_DIAMOND:
			{
				m_noneMoveObjects.emplace_back(std::make_unique<Diamond>(&gameTextures[O_DIAMOND], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth, (float)objHeight)));
				m_numOfDiamond++;
				break;
			}
			case C_STONE:
			{
				m_noneMoveObjects.emplace_back(std::make_unique<Stone>(&gameTextures[O_STONE], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth - 3, (float)objHeight - 3)));
				break;
			}
			case C_WALL:
			{
				m_noneMoveObjects.emplace_back(std::make_unique<Wall>(&gameTextures[O_WALL], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth, (float)objHeight)));
				break;
			}
			case C_GIFT:
			{
				switch ((rand() % 3) + 1)
				{
				case 1:
					if (m_time > -1)
					{
						m_noneMoveObjects.emplace_back(std::make_unique<ExtraTime>(&gameTextures[O_EXTRA_TIME_GIFT], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth, (float)objHeight)));
						break;
					}
				case 2:
					m_noneMoveObjects.emplace_back(std::make_unique<ExtraScore>(&gameTextures[O_EXTRA_SCORE_GIFT], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth, (float)objHeight)));
					break;
				case 3:
					m_noneMoveObjects.emplace_back(std::make_unique<ExtraStons>(&gameTextures[O_EXTRA_STONES_GIFT], sf::Vector2f((float)(j * objWidth), (float)(i * objHeight)), sf::Vector2f((float)objWidth, (float)objHeight)));
					break;
				}
				break;
			}
			default:
				break;
			}
		}
	}

}


void Board::drowBoard(sf::RenderWindow& window)
{
	window.draw(m_levelBackground);

	for (int i = 0; i < m_noneMoveObjects.size(); i++)
		m_noneMoveObjects[i]->draw(window);

	for (int i = 0; i < m_monsters.size(); i++)
		m_monsters[i]->draw(window);

	m_digger.draw(window);
}


void Board::MoveDigger(sf::Time deltaTime)
{
	m_diamondIsEaten = false;
	m_digger.moveDigger(deltaTime);
	handleCollisions(m_digger);

	std::experimental::erase_if(m_noneMoveObjects, [](auto& nonmoving)
		{
			return nonmoving->isDisposed();
		});
}

void Board::MovMonsters(sf::Time deltaTime)
{
	for (int i = 0; i < m_monsters.size(); i++)
	{
		m_monsters[i]->move(deltaTime, m_digger.getPosition());
		handleCollisions(*m_monsters[i]);
	}
}

void Board::resetLoc()
{
	for (int i = 0; i < m_monsters.size(); ++i)
	{
		m_monsters[i]->resetToStartLoc();
	}
	m_digger.resetToStartLoc();
}

int Board::getDiggerStones()const
{
	return m_digger.getNumberOfStones();
}

int Board::getTime()const
{
	return m_time;
}

void Board::setTime(int levelTime)
{
	m_time = levelTime;
}

bool Board::isDiggerDead()const
{
	return m_digger.isdead();
}

void Board::setDiggerAlive(bool isdead)
{
	m_digger.setIsDead(isdead);
}

void Board::handleCollisions(BaseObject& baseobject)
{
	for (auto& nonmoving : m_noneMoveObjects)
	{
		if (baseobject.checkCollision(nonmoving->getGlobalBounds()))
		{
			baseobject.collide(*nonmoving);
			if (m_digger.isDiamondEaten())
			{
				--m_numOfDiamond;
				m_diamondIsEaten = true;
				m_digger.setDiamondEaten(false);
			}
		}
	}
	for (auto& monsters : m_monsters)
	{
		if (baseobject.checkCollision(monsters->getGlobalBounds()))
		{
			baseobject.collide(*monsters);
		}
	}
}

bool Board::levelFinished()
{
	if (m_numOfDiamond == 0)
		return true;
	return false;
}

void Board::MoveObjects(sf::Time deltaTime)
{
	MoveDigger(deltaTime);
	MovMonsters(deltaTime);
}

bool Board::isDiamondEaten()const
{
	return m_diamondIsEaten;
}

bool Board::shouldWeAddTime()const
{
	return m_digger.shouldWeAddTime();
}

bool Board::shouldWeAddScore()const
{
	return m_digger.shouldWeAddScore();
}


void Board::InitializeData()
{
	m_monsters.clear();
	m_noneMoveObjects.clear();
	m_numOfDiamond = 0;
}


