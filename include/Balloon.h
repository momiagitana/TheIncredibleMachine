#pragma once

#include "GameObj.h"
#include "Factory.h" //fix needs to add to base class

const double BALLOON_GRAVITY = 0.2;
const int    BALLOON_WIDTH = 90;
const int 	 BALLOON_HEIGHT = 73;

class Balloon : public GameObj
{
public:
	Balloon(const ObjInfo info, const bool movable, b2World &world);
	void draw(sf::RenderWindow& window);
	void animation();
	void backToStartingPlace(); //fix override
	void setStatus(const bool status); //fix override
	
private:
	static bool m_registerit;
};
