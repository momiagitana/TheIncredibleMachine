#include <iostream>
#include "FileHandler.h"

const std::string END_PART = "-" ;
const int NUM_OF_PARTS = 4;

FileHandler::FileHandler(const std::string& fileName, bool read)
{
	if(read)
		m_file.open(fileName);

	else //open for append 
		m_file.open("newLevel.txt", std::ios::in | std::ios::out | std::ios::app);
}

FileHandler::~FileHandler()
{
	if (m_file.is_open())
		m_file.close();
}

ObjInfo FileHandler::buildObjInfo(std::stringstream& lineBuffer)
{
	ObjInfo obj;
	std::string objTyp,
		x_loc, y_loc,
		angle, size, fliped;

	lineBuffer >> objTyp >> x_loc >> y_loc >> size >> angle >> fliped;
	obj._typ = strToEnum(objTyp);
	obj._loc = sf::Vector2f(std::stof(x_loc), std::stof(y_loc));
	obj._angle = std::stoi(angle);
	obj._size = std::stoi(size);
	obj._fliped = std::stoi(fliped);

	return obj;
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

	while (PartOflevel <= NUM_OF_PARTS)
	{
		std::getline(m_file, line);
		if (line == END_PART) 
		{
			PartOflevel++;
			continue;
		}
		auto buffer = std::stringstream(line);

		switch (PartOflevel)
		{
		case 1:
		{
			currLevel.addBoardObj(buildObjInfo(buffer));
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
		angle,
		fliped;

	for (auto& obj : objects)
	{
		objTyp = enumToStr(obj._typ) + " ";
		x_loc = std::to_string(obj._loc.x)+ " ";
		y_loc = std::to_string(obj._loc.y) + " ";
		size = std::to_string(obj._size) + " ";
		angle = std::to_string(obj._angle) + " ";
		fliped = std::to_string(obj._fliped) + "\n";
		m_file << objTyp << x_loc << y_loc << size << angle << fliped;
	}	 
	m_file << "-\n-\n-\n-\n";
}

Type_t FileHandler::strToEnum(const std::string& str)
{
	if (str == "balloon") 			return balloon;
	else if (str == "basketBall") 	return basketBall;
	else if (str == "baseBall") 	return baseBall;
	else if (str == "bowlingBall") 	return bowlingBall;
	else if (str == "conveyor") 	return conveyor;
	else if (str == "brickWall") 	return brickWall;
	else if (str == "mouseEngine")	return mouseEngine;
	else if (str == "belt")			return belt;
	return none;

}

std::string FileHandler::enumToStr(Type_t obj)
{
	if (obj == balloon ) 			return "balloon";
	else if (obj == basketBall ) 	return "basketBall";
	else if (obj == baseBall ) 		return "baseBall";
	else if (obj == bowlingBall ) 	return "bowlingBall";
	else if (obj == conveyor ) 		return "conveyor";
	else if (obj == brickWall ) 	return "brickWall";
	else if (obj == mouseEngine )	return "mouseEngine";
	else if (obj == belt )	return "belt";
}//add obj fix




