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
#include "BasketBall.h"
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

    HitMap initializeCollisionMap();
 
};

namespace
{

    void basketWall(GameObj& object1, GameObj& object2)
    {
        // BasketBall& bsktBall = static_cast<BasketBall&>(object1);
        // BrickWall& brick    = static_cast<BrickWall&>(object2);

        //bsktBall.getPhysical().applyForce();

        std::cout << "BasketBall and Wall collision!" << std::endl;
    }
    void wallBasket(GameObj& object1, GameObj& object2)
    {
        basketWall(object2,object1);
    }


    void balloonWall(GameObj& object1, GameObj& object2)
    {
        std::cout << "balloon and Wall collision!" << std::endl;
    }
    void wallBalloon(GameObj& object1, GameObj& object2)
    {
        balloonWall(object2,object1);
    }


    void basketBalloon(GameObj& object1, GameObj& object2)
    {
        std::cout << "balloon and Wall basketBall!" << std::endl;
    }
    void balloonBasket(GameObj& object1, GameObj& object2)
    {
        basketBalloon(object2,object1);
    }


    void wallBaseball(GameObj& object1, GameObj& object2)
    {
        std::cout<<"wall and baseball collided"<<std::endl;
    }
    void baseballWall(GameObj& object1, GameObj& object2)
    {
        wallBaseball(object2,object1);
    }


    void balloonBaseball(GameObj& object1, GameObj& object2)
    {
        // Balloon& ballonn = static_cast<Balloon&>(balloon);
        // BaseBall&  ball  = static_cast<BaseBall&>(baseBall);

        std::cout << "balloonn and baseball collision!" << std::endl;
    }
    void baseballBalloon(GameObj& object1, GameObj& object2)
    {
        balloonBaseball(object2,object1);
    }

        
    void baseballBaseball(GameObj& object1, GameObj& object2)
    {
       std::cout << "baseball and baseball collision!" << std::endl;
    }


    void balloonBalloon(GameObj& object1, GameObj& object2)
    {
       std::cout << "balloonn and balloonn collision!" << std::endl;
    }


    void basketBasket(GameObj& object1, GameObj& object2)
    {
        std::cout << "basketBall and basketBall collision!" << std::endl;
    }



}
