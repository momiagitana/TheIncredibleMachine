#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using std::ostringstream;

class Button : public BaseImg
{
public:

	Button(const sf::Vector2f& center, const Type_t obj);
	virtual ~Button(){}

	Type_t getType()const;

	virtual bool mouseOnMe(const sf::Vector2f loc) const;
	virtual Type_t handleClick(const sf::Vector2f loc);

	
private:
	Type_t m_type;
};