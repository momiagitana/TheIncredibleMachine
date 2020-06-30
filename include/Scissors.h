#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Factory.h"//fix needs to add to base class

class Scissors : public GameObj
{
public:
	Scissors(const sf::Vector2f& center, bool movable, b2World &world, Type_t type);
private:

    static bool m_registerit ;
};
