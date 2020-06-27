#include "BrickWall.h"

BrickWall::BrickWall (ObjInfo info, bool movable, b2World &world)
    :Resizable(info, movable, world, brickWall)
{
}

bool BrickWall::m_registerit = ObjFactory::registerit(brickWall, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<BrickWall>(info,movable,world);});
