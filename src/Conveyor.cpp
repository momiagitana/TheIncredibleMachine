#include "Conveyor.h"

Conveyor::Conveyor (const sf::Vector2f& center, bool movable, b2World &world)
    :Resizable(center, movable, world, conveyor)
{
}

bool Conveyor::m_registerit = ObjFactory::registerit(conveyor, [](const sf::Vector2f& center, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<Conveyor>(center,movable,world); });
