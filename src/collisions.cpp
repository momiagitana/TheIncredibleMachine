#include "Collisions.h"

Collisions::Collisions()
{
      m_hitMap[Key(typeid(Balloon), typeid(BaseBall))] = &balloonAndBaseball;
      m_hitMap[Key(typeid(BasketBall), typeid(BrickWall))] = &basketWall;
      m_hitMap[Key(typeid(Balloon), typeid(BrickWall))] = &balloonWall;
      m_hitMap[Key(typeid(BasketBall), typeid(Balloon))] = &basketBalloon;
}

HitFunctionPtr Collisions::lookup(const std::type_index& class1, const std::type_index& class2)
{
    auto mapEntry = m_hitMap.find(std::make_pair(class1, class2));
    
    if (mapEntry == m_hitMap.end())
    { 
        return nullptr;
    }

    return mapEntry->second;
}

void Collisions::processCollision(GameObj& object1, GameObj& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        std::cout<<"there is no func for these objects"<<std::endl;
        return;
    }
    phf(object1, object2);
}

// void Collisions::for_each_pair(FwdIt begin, FwdIt end, Fn fn)
// {
//     for(; begin != end; ++begin)
//         for(auto second = begin+1; second != end; ++second)
//             fn(*begin, *second);
// }
