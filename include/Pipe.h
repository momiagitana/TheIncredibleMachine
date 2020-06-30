#pragma once
#include"Resizable.h"
#include "Factory.h"//fix needs to add to base class


class Pipe : public Resizable
{
public:
	Pipe (ObjInfo info, bool movable, b2World &world);
	
private:
	static bool m_registerit;
};
