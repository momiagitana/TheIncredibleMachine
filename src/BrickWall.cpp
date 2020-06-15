#include "BrickWall.h"

BrickWallH::BrickWallH (const sf::Vector2f& center, bool movable, int which, b2World &world)
    :Resizable(center,sf::Vector2f(25.f,25.f),ResourceManager::instance().getTexture(brickWallH), which, movable, world)
{
}


