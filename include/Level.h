#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Level
{
public:

	Level(std::vector<std::string>,int,int,int,int);
	char getCell(int, int) const;
	int getRows()const;
	int getCols() const; 
	int getStones() const;
	int getTime() const;

private:

	int m_rows;
	int m_cols;
	int m_stones;
	int m_time;
	std::vector<std::string> m_level;
};
