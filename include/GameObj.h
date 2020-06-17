#pragma once

#include <SFML/Graphics.hpp>

#include "BaseImg.h"
#include "PhysicsObj.h"


class GameObj : public BaseImg
{
public:

	GameObj(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, bool movable, b2World &world);

	void draw (sf::RenderWindow&);

	void setInitialLoc();

	void setGravityScale(float);

private:

	PhysicsObj m_phyObj;
	bool m_movable;
	int m_ID;
	sf::Vector2f m_initialLoc;
	
	void updateLoc();

	
};
