#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "globals.h"
#include "baseImg.h"
#include "GameObj.h"

using funcPtr = std::shared_ptr<GameObj>(*)(const sf::Vector2f&, bool, b2World &);
class ObjFactory
{  
public:

    ObjFactory();
	static std::shared_ptr<GameObj> create(const Type_t& ,const sf::Vector2f& , bool , b2World &);
	static bool registerit(const Type_t& , funcPtr);

private:
	static auto& getMap() 
    {
		static std::map<Type_t, funcPtr> map;
		return map;
	}
};

