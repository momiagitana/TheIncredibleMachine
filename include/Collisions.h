#pragma once

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <vector>
#include <memory>
#include <exception>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "GameObj.h"
#include "BaseBall.h"
#include "Balloon.h"

using HitFunctionPtr = void (*)(GameObj&, GameObj&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

class Collisions
{

public:

    Collisions();

    HitMap initializeCollisionMap();

    void processCollision(GameObj& object1, GameObj& object2);
  
    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);
 
   // void balloonAndBaseball(GameObj& balloon, GameObj& baseBall);
   template <typename FwdIt, typename Fn>
   void  for_each_pair(FwdIt begin, FwdIt end, Fn fn);

private:

    HitMap m_hitMap;
 
};
namespace
{

void balloonAndBaseball(GameObj& balloon, GameObj& baseBall)
{

    Balloon& ballonn = static_cast<Balloon&>(balloon);
    BaseBall&  ball  = static_cast<BaseBall&>(baseBall);

    std::cout << "balloonn and baseball collision!" << std::endl;
}
}
