#include "Collisions.h"

Collisions::Collisions()
{
      m_hitMap[Key(typeid(balloon), typeid(baseBall))] = &balloonAndBaseball;
}

// HitMap Collisions::initializeCollisionMap()
// {
//     HitMap phm;

//     phm[Key(typeid(balloon), typeid(baseBall))] = &balloonAndBaseball;

//     return phm;
// }

HitFunctionPtr Collisions::lookup(const std::type_index& class1, const std::type_index& class2)
{
    //static HitMap collisionMap = initializeCollisionMap();

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
        std::cout<<"not in table\n";
    }
    phf(object1, object2);
}

template <typename FwdIt, typename Fn>
void Collisions::for_each_pair(FwdIt begin, FwdIt end, Fn fn)
{
    for(; begin != end; ++begin)
        for(auto second = begin+1; second != end; ++second)
            fn(*begin, *second);
}
