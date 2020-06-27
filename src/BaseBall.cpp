#include "BaseBall.h"


BaseBall::BaseBall (ObjInfo info, bool movable, b2World &world)
    :Ball(info._loc, movable, world, baseBall)
{
}


bool BaseBall::m_registerit = ObjFactory::registerit(baseBall, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<BaseBall>(info,movable,world); });