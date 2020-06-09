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

//Level FileHandler::readLevelFromFile()
//{
//	
//}

bool FileHandler::ifEndOfFile()
{
	return endOfFile;
}








