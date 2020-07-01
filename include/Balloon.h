#pragma once

#include "GameObj.h"
#include "ResourceManager.h"
#include "Factory.h" //fix needs to add to base class

class Balloon : public GameObj
{
public:
	Balloon(ObjInfo info, bool movable, b2World &world);
	void draw(sf::RenderWindow& window);
	void animation();
	void backToStartingPlace(); //fix override
	
private:
	static bool m_registerit;
	
};
