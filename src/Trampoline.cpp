#include "Trampoline.h"

Trampoline::Trampoline(ObjInfo info, bool movable, b2World &world)
    :GameObj(info._loc, STATIC, movable, world, info._typ)
{
}

bool Trampoline::m_registerit = ObjFactory::registerit(trampoline, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Trampoline>(info,movable,world);});
