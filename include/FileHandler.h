#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Board.h"
#include "Globals.h"
#include "Level.h"

class FileHandler
{
public:

	FileHandler(const std::string&);
	~FileHandler();
	Level readLevelFromFile();
	bool ifEndOfFile();

private:

	bool endOfFile = false;
	std::fstream m_file;
};

