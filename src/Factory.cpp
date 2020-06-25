#include "Factory.h"

ObjFactory::ObjFactory()
{
}


std::shared_ptr<GameObj> ObjFactory::create(ObjInfo info, bool movable, b2World &world) //fix const &
  
{
	auto it = ObjFactory::getMap().find(info._typ);
	if (it == ObjFactory::getMap().end())
		return nullptr;

	return it->second(info,movable,world);
}

bool ObjFactory::registerit(const Type_t& name, funcPtr f) 
{
	ObjFactory::getMap().emplace(name, f);
	return true;
}