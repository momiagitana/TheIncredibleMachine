#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "globals.h"
#include "baseImg.h"
#include "GameObj.h"


using funcPtr = std::unique_ptr<GameObj>(*)(const sf::Vector2f&, bool, b2World &);//zalman fix angle size objinfo

class ObjFactory
{  
public:

    ObjFactory();

	
	static std::unique_ptr<GameObj> create(const ObjInfo&, bool , b2World &wold);

	static bool registerit(const Type_t& , funcPtr);

private:
	static auto& getMap() 
    {
		static std::map<Type_t, funcPtr> map;
		return map;
	}
};

