#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include "globals.h"
#include "Level.h"


class FileHandler
{
public:

	FileHandler(const std::string&);
	~FileHandler();
	std::vector<Level> readLevels();

private:

	Level getlevel();
	GameObject_t strToEnum(const std::string& str);
	std::fstream m_file;
};

