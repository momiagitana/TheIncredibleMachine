#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Factory.h"

class Trampoline : public GameObj
{
public:
	Trampoline(ObjInfo info, bool movable, b2World &world);//fix const& objInfo
private:
	static bool m_registerit;

};
