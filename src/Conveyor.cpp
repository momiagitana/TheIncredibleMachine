#include "Conveyor.h"

Conveyor::Conveyor (ObjInfo info, bool movable, b2World &world)
    :Resizable(info, movable, world, conveyor)
{
}

bool Conveyor::m_registerit = ObjFactory::registerit(conveyor, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<Conveyor>(info,movable,world); });
