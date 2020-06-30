#include "Pipe.h"

Pipe::Pipe (ObjInfo info, bool movable, b2World &world)
    :Resizable(info, movable, world, brickWall)
{
}

bool Pipe::m_registerit = ObjFactory::registerit(pipe, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Pipe>(info,movable,world);});
