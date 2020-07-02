#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Ball : public GameObj
{
public:
	Ball(const sf::Vector2f&,const bool , b2World &,const Type_t);
	virtual ~Ball(){}
private:

};
