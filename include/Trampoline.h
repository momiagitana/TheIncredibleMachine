#pragma once
#include "GameObj.h"
#include "Factory.h"

class Trampoline : public GameObj
{
public:
	Trampoline(const ObjInfo info, const bool movable, b2World &world);
	void draw(sf::RenderWindow& window);
	void animation();

private:
	static bool m_registerit;
};
