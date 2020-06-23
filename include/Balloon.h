#pragma once

#include "GameObj.h"
#include "ResourceManager.h"
#include "Factory.h" //fix needs to add to base class

class Balloon : public GameObj
{
public:
	Balloon(const sf::Vector2f& center, bool movable, b2World &world);
	
private:
	static bool m_registerit;
	
};
