#include "Scissors.h"


Scissors::Scissors(const sf::Vector2f& center, bool movable, b2World &world, Type_t type)
    :GameObj(center, STATIC, movable, world, type)
{
}

bool Scissors::m_registerit = ObjFactory::registerit(scissors, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<Scissors>(info,movable,world); });

