#pragma once
#include"Ball.h"
#include "Factory.h"//fix needs to add to base class

class BaseBall : public Ball
{
public:
	BaseBall (ObjInfo info, bool movable, b2World &world);
	

private:
	static bool m_registerit;
};
