#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using std::ostringstream;

class Button : public BaseImg
{
public:

	Button(const sf::Vector2f& center,Type_t obj);
	virtual bool mouseOnMe(sf::Vector2f loc);
	Type_t getType();
	
private:
	Type_t m_type;
};