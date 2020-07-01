#include "PipeWall.h"

PipeWall::PipeWall (ObjInfo info, bool movable, b2World &world)
    :Resizable(info, movable, world, pipeWall)
{
}

bool PipeWall::m_registerit = ObjFactory::registerit(pipeWall, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<PipeWall>(info,movable,world);});
