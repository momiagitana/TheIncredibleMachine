#include <iostream>
#include "FileHandler.h"
#include <sstream>

FileHandler::FileHandler(const std::string& fileName)
{
	m_file.open(fileName);
}

FileHandler::~FileHandler()
{
	if (m_file.is_open())
		m_file.close();
}

Level FileHandler::getlevel()
{
	Level currLevel;
	int PartOflevel = 1;
	std::string line,
	            objTyp,
	            x_loc, y_loc,
		        x_size,y_size,
		        id,objAmount;

	while (PartOflevel <= 4)
	{
		std::getline(m_file, line);
		if (line == "-") //fix const
		{
			PartOflevel++;
			continue;
		}
		auto buffer = std::stringstream(line);

		switch (PartOflevel)
		{
		case 1:
		{
			buffer >> objTyp >> x_loc >> y_loc;
			int x = 6;
			currLevel.addBoardObj(strToEnum(objTyp), sf::Vector2f(std::stof(x_loc), std::stof(y_loc)));
			break;
		}
		case 2:
		{
			buffer >> objTyp >> objAmount;
			currLevel.addToolbarObj(strToEnum(objTyp), std::stoi(objAmount));
			break;
			
		}
		case 3:
		{
			buffer >> id >> x_size >> y_size >> x_loc >> y_loc;
			currLevel.addCondLoc(std::stoi(id), sf::Vector2f(std::stof(x_size), std::stof(y_size)), sf::Vector2f(std::stof(x_loc), std::stof(y_loc)));
			break;
		}
		case 4:
		{
			buffer >> id;
			currLevel.addCondAct(std::stoi(id));
			break;
		}
		}

	}
	m_file.get();
	return currLevel;
}

std::vector<Level> FileHandler::readLevels()
{
	std::vector<Level> levels;

	while (!m_file.eof())
	{
		levels.push_back(getlevel());
	}
	return levels;
}

GameObject_t FileHandler::strToEnum(const std::string& str)
{
	if (str == "balloon") return balloon;
	else if (str == "basketBall") return basketBall;
	else if (str == "baseBall") return baseBall;
	else if (str == "bowlingBall") return bowlingBall;
	else if (str == "conveyor") return conveyor;
	else if (str == "brickWallH") return brickWallH;
	else if (str == "brickWallV") return brickWallV;
	else if (str == "worker") return worker;
}




