#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Factory.h"//fix needs to add to base class

class Scissors : public GameObj
{
public:
	Scissors(ObjInfo info, bool movable, b2World &world);
private:

    static bool m_registerit ;
};
