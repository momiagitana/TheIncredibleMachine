#include "Collisions.h"

Collisions::Collisions()
{
    //   m_hitMap[Key(typeid(Balloon), typeid(BaseBall))] = &balloonBaseball;
    //   m_hitMap[Key(typeid(BaseBall), typeid(Balloon))] = &baseballBalloon;

    //   m_hitMap[Key(typeid(BasketBall), typeid(BrickWall))] = &basketWall;
    //   m_hitMap[Key(typeid(BrickWall), typeid(BasketBall))] = &wallBasket;

    //   m_hitMap[Key(typeid(Balloon), typeid(BrickWall))] = &balloonWall;
    //   m_hitMap[Key(typeid(BrickWall), typeid(Balloon))] = &wallBalloon;

    //   m_hitMap[Key(typeid(BasketBall), typeid(Balloon))] = &basketBalloon;
    //   m_hitMap[Key(typeid(Balloon), typeid(BasketBall))] = &balloonBasket;
     
    //   m_hitMap[Key(typeid(BrickWall), typeid(BaseBall))] = &wallBaseball;
    //   m_hitMap[Key(typeid(BaseBall), typeid(BrickWall))] = &baseballWall;
}

HitMap Collisions::initializeCollisionMap()
{
    HitMap map;

      map[Key(typeid(Balloon), typeid(BaseBall))]     = &balloonBaseball;
      map[Key(typeid(BaseBall), typeid(Balloon))]     = &baseballBalloon;

      map[Key(typeid(BasketBall), typeid(BrickWall))] = &basketWall;
      map[Key(typeid(BrickWall), typeid(BasketBall))] = &wallBasket;

      map[Key(typeid(Balloon), typeid(BrickWall))]    = &balloonWall;
      map[Key(typeid(BrickWall), typeid(Balloon))]    = &wallBalloon;

      map[Key(typeid(BasketBall), typeid(Balloon))]   = &basketBalloon;
      map[Key(typeid(Balloon), typeid(BasketBall))]   = &balloonBasket;
     
      map[Key(typeid(BrickWall), typeid(BaseBall))]   = &wallBaseball;
      map[Key(typeid(BaseBall), typeid(BrickWall))]   = &baseballWall;

      map[Key(typeid(BaseBall), typeid(BaseBall))]   = &baseballBaseball;

      map[Key(typeid(Balloon), typeid(Balloon))]   = &balloonBalloon;

      map[Key(typeid(BasketBall), typeid(BasketBall))]   = &basketBasket;
      

    return map;
}

HitFunctionPtr Collisions::lookup(const std::type_index& class1, const std::type_index& class2)
{
    static HitMap collisionMap = initializeCollisionMap();

    auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
    
    if (mapEntry == collisionMap.end())
    { 
        return nullptr;
    }

    return mapEntry->second;
}

void Collisions::processCollision(GameObj& object1, GameObj& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));

    std::cout<<typeid(object1).name()<<std::endl;
    std::cout<<typeid(object2).name()<<std::endl;

    if (!phf)
    {
        std::cout<<"there is no func for these objects"<<std::endl;
        return;
    }

    phf(object1, object2);
}
