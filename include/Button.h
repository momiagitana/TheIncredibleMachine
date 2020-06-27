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

	Type_t getType()const;

	virtual Type_t mouseOnMe(sf::Vector2f loc);

	
private:
	Type_t m_type;
};