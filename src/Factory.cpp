#include "Factory.h"

ObjFactory::ObjFactory()
{
}

std::unique_ptr<GameObj> ObjFactory::create(const Type_t& name,const sf::Vector2f& center, bool movable, b2World &world) 
{
	auto it = ObjFactory::getMap().find(name);

	if (it == ObjFactory::getMap().end())
		return nullptr;

	return it->second(center,movable,world);
}

bool ObjFactory::registerit(const Type_t& name, funcPtr f) 
{
	ObjFactory::getMap().emplace(name, f);
	return true;
}