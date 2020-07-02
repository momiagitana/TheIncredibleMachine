#include "Conveyor.h"

Conveyor::Conveyor (const ObjInfo info, const bool movable, b2World &world)
    :Connectable(info, movable, world, 1)
{
    setIntRect(sf::IntRect(0,0,80,16));//fix
    updateBodySize();
    
}

bool Conveyor::m_registerit = ObjFactory::registerit(conveyor, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<Conveyor>(info,movable,world); });
