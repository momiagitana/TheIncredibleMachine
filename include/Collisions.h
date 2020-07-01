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
#include "Conveyor.h"
#include "MouseEngine.h"
#include "Trampoline.h"
#include "Scissors.h"


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

    int aboveOrBelow(GameObj& object1, GameObj& object2);
 
};

namespace
{

    void scissorsBalloon(GameObj& object1, GameObj& object2)
    {
        if(object1.getGlobalBounds().left > object2.getGlobalBounds().left+object2.getGlobalBounds().width/2)
            object2.setStatus(true);
    }
    void balloonScissors(GameObj& object1, GameObj& object2)
    {
        scissorsBalloon(object2,object1);
    }


    void conveyorBalloon(GameObj& object1, GameObj& object2)
    {
        Conveyor&  conv  = static_cast<Conveyor&>(object1);
        
        if(conv.isOn())
        {
            b2Vec2 force;
            force.x = 0.0125;
            force.y = 0.0;

            force.x *= object1.aboveOrBelow(object2);

            object2.applyForce(force);
        }
        std::cout << "conveyor and balloon collision!" << std::endl;
    }
    void balloonConveyor(GameObj& object1, GameObj& object2)
    {
        conveyorBalloon(object2, object1);
    }


    void conveyorBasket(GameObj& object1, GameObj& object2)
    {
        Conveyor&  conv  = static_cast<Conveyor&>(object1);
    
        if(conv.isOn())
        {
            b2Vec2 force;
            force.x = 0.05;
            force.y = 0.0;

            force.x *= object1.aboveOrBelow(object2);

            object2.applyForce(force);
        }
        std::cout << "conveyor and balloon collision!" << std::endl;
    }
    void basketConveyor(GameObj& object1, GameObj& object2)
    {
        conveyorBasket(object2, object1);
    }


    void conveyorBase(GameObj& object1, GameObj& object2)
    {
       Conveyor&  conv  = static_cast<Conveyor&>(object1);

       if(conv.isOn())
        {
            b2Vec2 force;
            force.x = 0.005;
            force.y = 0.0;

            force.x *= object1.aboveOrBelow(object2);

            object2.applyForce(force);
        }

        std::cout << "conveyor and balloon collision!" << std::endl;
    }
    void baseConveyor(GameObj& object1, GameObj& object2)
    {
        conveyorBase(object2, object1);
    }


    void ballEngine(GameObj& object1, GameObj& object2)
    {
        MouseEngine&  engine  = static_cast<MouseEngine&>(object2);

        engine.setStatus(true);
    
    }
    void engineBall(GameObj& object1, GameObj& object2)
    {
        ballEngine(object2, object1);
    }

    void trampBall(GameObj& object1, GameObj& object2)
    {
        if(object1.isBelow(object2))
        {
            b2Vec2 force;
            force.x = 0.0;
            force.y = 0.125;

            object2.applyForce(force);
        }

        std::cout << "trampoline and Basketball collision!" << std::endl;
    }
    void ballTramp(GameObj& object1, GameObj& object2)
    {
        trampBall(object2, object1);
    }

}
