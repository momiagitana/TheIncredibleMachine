#pragma once
#include "Ball.h"
#include "Factory.h"//fix needs to add to base class


class BowlingBall : public Ball
{
public:
	BowlingBall(ObjInfo info, bool movable, b2World& world);

private:
	static bool m_registerit;
};
