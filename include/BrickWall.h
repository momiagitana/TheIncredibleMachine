#pragma once
#include"Resizable.h"


class BrickWall : public Resizable
{
public:
	BrickWall (const sf::Vector2f& center, bool movable, b2World &world);
	
	//void makeItGrow();
private:

};
