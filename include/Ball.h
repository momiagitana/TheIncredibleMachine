#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Ball : public GameObj
{
public:
	Ball(const sf::Vector2f& center, sf::Texture* texture, bool movable, b2World &world, GameObject_t);
	
private:
	int m_radius;
};
