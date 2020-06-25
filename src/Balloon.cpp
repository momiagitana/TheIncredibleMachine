#include "Balloon.h"


Balloon::Balloon(const sf::Vector2f& center, bool movable, b2World &world)
    :GameObj(center, true, movable, world, balloon)
{
    setGravityScale(-0.3);
}

bool Balloon::m_registerit = ObjFactory::registerit(balloon, [](const sf::Vector2f& center, bool movable, b2World &world) -> std::unique_ptr<GameObj> { return std::make_unique<Balloon>(center,movable,world); });
