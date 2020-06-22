#pragma once

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <vector>
#include <memory>
#include <algorithm>
#include <exception>

#include "GameObj.h"
#include "BaseBall.h"
#include "Balloon.h"
#include "Basketball.h"
#include "BrickWall.h"


using HitFunctionPtr = void (*)(GameObj&, GameObj&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;

class Collisions
{

public:

    Collisions();

    void processCollision(GameObj& object1, GameObj& object2);
  
    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);
 
   // void balloonAndBaseball(GameObj& balloon, GameObj& baseBall);
//    template <typename FwdIt, typename Fn>
//    void  for_each_pair(FwdIt begin, FwdIt end, Fn fn);

private:

    HitMap m_hitMap;
 
};


namespace
{

void balloonAndBaseball(GameObj& object1, GameObj& object2)
{

    // Balloon& ballonn = static_cast<Balloon&>(balloon);
    // BaseBall&  ball  = static_cast<BaseBall&>(baseBall);

    std::cout << "balloonn and baseball collision!" << std::endl;
}

void basketWall(GameObj& object1, GameObj& object2)
{
    BasketBall& bsktBall = static_cast<BasketBall&>(object1);
    BrickWallH& brick    = static_cast<BrickWallH&>(object2);

    bsktBall.getPhysical().applyForce();

    std::cout << "BasketBall and Wall collision!" << std::endl;
}

void balloonWall(GameObj& object1, GameObj& object2)
{
    std::cout << "balloon and Wall collision!" << std::endl;
}
// struct UnknownCollision : public std::runtime_error
// {
//     UnknownCollision(GameObj& a, GameObj& b)
//         : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
//     {
//     }
// };

void basketBalloon(GameObj& object1, GameObj& object2)
{
    std::cout << "balloon and Wall basketBall!" << std::endl;
}
}

