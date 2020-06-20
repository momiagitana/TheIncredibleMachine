#include "BrickWall.h"

BrickWall::BrickWall (const sf::Vector2f& center, bool movable, b2World &world)
    :Resizable(center, movable, world, brickWall)
{
}


// void BrickWallH::makeItBigger()
// {
//     Resizable::makeItBigger();
// }

// void BrickWallH::makeItSmaller()
// {
//     Resizable::makeItSmaller();
// }