#include "Factory.h"

ObjFactory::ObjFactory()
{
}

std::unique_ptr<GameObj> ObjFactory::create(const ObjInfo& info, bool movable, b2World &world) 
{
	auto it = ObjFactory::getMap().find(info._typ);

	if (it == ObjFactory::getMap().end())
		return nullptr;

	return it->second(info._loc,movable,world);
}

bool ObjFactory::registerit(const Type_t& name, funcPtr f) 
{
	ObjFactory::getMap().emplace(name, f);
	return true;
}