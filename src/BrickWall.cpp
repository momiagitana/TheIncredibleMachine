#include "BrickWall.h"

BrickWallH::BrickWallH (const sf::Vector2f& center, bool movable, b2World &world)
    :Resizable(center,ResourceManager::instance().getTexture(brickWallH)->getSize(), movable, world, brickWallH)
{
}


