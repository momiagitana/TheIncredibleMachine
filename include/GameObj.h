#pragma once

#include <SFML/Graphics.hpp>

#include "BaseImg.h"
#include "PhysicsObj.h"




class GameObj : public BaseImg
{
public:

	GameObj(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World &world);

	void draw (sf::RenderWindow&);


private:

	PhysicsObj m_phyObj;
	
	void updateLoc();

	
};

