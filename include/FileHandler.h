#pragma once

#include <fstream>
#include <SFML/Graphics.hpp>
#include <string>
#include "globals.h"
#include "Level.h"
#include <sstream>

class FileHandler
{
public:

	FileHandler(const std::string&, const bool);
	~FileHandler();
	std::vector<Level> readLevels();
	void saveNewLevel(const std::vector< ObjInfo>&);

private:

	ObjInfo buildObjInfo(std::stringstream &);
	Level getlevel();
	Type_t strToEnum(const std::string& str) const;
	std::string enumToStr(const Type_t) const;
	std::fstream m_file;
};

