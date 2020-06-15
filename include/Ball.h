#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Ball : public GameObj
{
public:
	Ball(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool movable, b2World &world);
	
private:
	int m_radius;
};
