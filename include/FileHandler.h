#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include "globals.h"
#include "Level.h"


class FileHandler
{
public:

	FileHandler(const std::string&, bool);
	~FileHandler();
	std::vector<Level> readLevels();
	void saveNewLevel(const std::vector< ObjInfo>&);

private:

	Level getlevel();
	Type_t strToEnum(const std::string& str);
	std::string enumToStr(Type_t);
	std::fstream m_file;
};

