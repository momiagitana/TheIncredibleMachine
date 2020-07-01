#include "FancyWall.h"

FancyWall::FancyWall (ObjInfo info, bool movable, b2World &world)
    :Resizable(info, movable, world, fancyWall)
{
}

bool FancyWall::m_registerit = ObjFactory::registerit(fancyWall, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<FancyWall>(info,movable,world);});
