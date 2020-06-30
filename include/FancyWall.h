#pragma once
#include"Resizable.h"
#include "Factory.h"//fix needs to add to base class


class FancyWall : public Resizable
{
public:
	FancyWall (ObjInfo info, bool movable, b2World &world);
	
private:
	static bool m_registerit;
};
