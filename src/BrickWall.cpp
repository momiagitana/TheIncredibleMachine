#include "BrickWall.h"

BrickWall::BrickWall (const sf::Vector2f& center, bool movable, b2World &world)
    :Resizable(center, movable, world, brickWall)
{
}

bool BrickWall::m_registerit = ObjFactory::registerit(brickWall, [](const sf::Vector2f& center, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<BrickWall>(center,movable,world);});
