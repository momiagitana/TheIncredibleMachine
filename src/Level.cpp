#include "Level.h"


Level::Level(std::vector<std::string> level, int rows, int cols, int stones,int time) :m_level(level), m_rows(rows),m_cols(cols),m_stones(stones),m_time(time){}


char Level::getCell(int i, int j) const
{
	return m_level[i][j];
}

int Level::getCols() const
{
	return m_cols;
}

int Level::getStones() const
{
	return m_stones;
}

int Level::getTime() const
{
	return m_time;
}

int Level::getRows() const
{
	return m_rows;
}