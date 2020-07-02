#pragma once
#include "Ball.h"
#include "Factory.h"//fix needs to add to base class


class BasketBall : public Ball
{
public:
	BasketBall(const ObjInfo info, const bool movable, b2World &world);

private:
	static bool m_registerit;
};
