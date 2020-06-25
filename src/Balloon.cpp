#include "Balloon.h"


Balloon::Balloon(ObjInfo info, bool movable, b2World &world)
    :GameObj(info._loc, true, movable, world, balloon)
{
    setGravityScale(-0.3);
}

bool Balloon::m_registerit = ObjFactory::registerit(balloon, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Balloon>(info,movable,world); });
