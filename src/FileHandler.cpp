#include<iostream>
#include "FileHandler.h"

FileHandler::FileHandler(const std::string& fileName) 
{
	m_file.open(fileName);
}

FileHandler::~FileHandler()
{
	if (m_file.is_open())
		m_file.close();
}

Level FileHandler::readLevelFromFile()
{
	std::vector<std::string> level;
	std::string rows, cols, stones,time,line;

	int irows;
	int icols;
	int istones;
	int itime;

	m_file >> rows >> cols >> stones >> time ;

	irows = stoi(rows);
	icols = stoi(cols);
	istones = stoi(stones);
	itime = stoi(time);
	m_file.get();
	
	for (int i = 0; i < irows; i++)
	{
		std::getline(m_file, line);
		level.push_back(line);
	}
	if (m_file.eof())
		endOfFile = true;

	return Level(level, irows, icols, istones,itime);
}

bool FileHandler::ifEndOfFile()
{
	return endOfFile;
}








