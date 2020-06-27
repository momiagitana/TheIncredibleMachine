#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <vector>

#include "globals.h"
#include "baseImg.h"
#include "GameObj.h"


using funcPtr = std::shared_ptr<GameObj>(*)(ObjInfo, bool, b2World &);//zalman fix angle size objinfo

class ObjFactory
{  
public:

    ObjFactory();

	static std::shared_ptr<GameObj> create(ObjInfo, bool , b2World &wold);

	static bool registerit(const Type_t& , funcPtr);

private:
	static auto& getMap() 
    {
		static std::map<Type_t, funcPtr> map;
		return map;
	}
};

