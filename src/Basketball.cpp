#include "BasketBall.h"


BasketBall::BasketBall (ObjInfo info, bool movable, b2World &world)
    :Ball(info._loc, movable, world, basketBall)
{
}

bool BasketBall::m_registerit = ObjFactory::registerit(basketBall, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<BasketBall>(info,movable,world); });