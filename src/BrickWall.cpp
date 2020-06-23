#include "BrickWall.h"

BrickWall::BrickWall (const sf::Vector2f& center, bool movable, b2World &world)
    :Resizable(center, movable, world, brickWall)
{
}

bool BrickWall::m_registerit = ObjFactory::registerit(brickWall, [](const sf::Vector2f& center, bool movable, b2World &world) -> std::unique_ptr<GameObj> { return std::make_unique<BrickWall>(center,movable,world); });
// void BrickWallH::makeItBigger()
// {
//     Resizable::makeItBigger();
// }

// void BrickWallH::makeItSmaller()
// {
//     Resizable::makeItSmaller();
// }