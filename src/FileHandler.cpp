#include <iostream>
#include "FileHandler.h"
#include <sstream>

FileHandler::FileHandler(const std::string& fileName, bool read)
{
	if(read)
		m_file.open(fileName);

	else //open for append 
		m_file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
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

void FileHandler::saveNewLevel(const std::vector<ObjInfo>& objects)
{
	// m_file.clear();
	m_file << "\n";

	std::string objTyp,
		x_loc, y_loc,
		size,
		angle;

	for (auto& obj : objects)
	{
		objTyp = enumToStr(obj._typ) + " ";
		x_loc = std::to_string(obj._loc.x)+ " ";
		y_loc = std::to_string(obj._loc.y) + " ";
		size = std::to_string(obj._size) + " ";
		angle = std::to_string(obj._angle) + "\n";
		m_file << objTyp << x_loc << y_loc;
		if(size != "-1" && angle != "-1")
			m_file<< size << angle;
	}	 
	m_file << "-\n-\n-\n-\n";
}

Type_t FileHandler::strToEnum(const std::string& str)
{
	if (str == "balloon") return balloon;
	else if (str == "basketBall") return basketBall;
	else if (str == "baseBall") return baseBall;
	else if (str == "bowlingBall") return bowlingBall;
	else if (str == "conveyor") return conveyor;
	else if (str == "brickWall") return brickWall;

}

std::string FileHandler::enumToStr(Type_t obj)
{
	if (obj == balloon ) return "balloon";
	else if (obj == basketBall ) return "basketBall";
	else if (obj == baseBall ) return "baseBall";
	else if (obj == bowlingBall ) return "bowlingBall";
	else if (obj == conveyor ) return "conveyor";
	else if (obj == brickWall ) return "brickWall";
}




