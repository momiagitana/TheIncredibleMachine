#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Ball : public GameObj
{
public:
	Ball(const sf::Vector2f&, bool , b2World &, Type_t);

private:

};
