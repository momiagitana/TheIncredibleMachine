#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Factory.h"//fix needs to add to base class

class Scissors : public GameObj
{
public:
	Scissors(const ObjInfo, const bool, b2World &);
private:

    static bool m_registerit ;
};
