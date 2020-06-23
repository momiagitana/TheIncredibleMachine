#pragma once
#include"Resizable.h"
#include "Factory.h"//fix needs to add to base class


class BrickWall : public Resizable
{
public:
	BrickWall (const sf::Vector2f& center, bool movable, b2World &world);
	
	//void makeItGrow();
private:
		static bool m_registerit;
};
