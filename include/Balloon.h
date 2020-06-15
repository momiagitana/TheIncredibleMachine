#pragma once

#include "GameObj.h"
#include "ResourceManager.h"

class Balloon : public GameObj
{
public:
	Balloon(const sf::Vector2f& center, bool movable, b2World &world);
	
private:
	
};
