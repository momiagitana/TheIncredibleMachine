#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Ball : public GameObj
{
public:
	Ball(const sf::Vector2f& center, const sf::Vector2u& size, bool movable, b2World &world, GameObject_t);
	
private:
	int m_radius;
};
