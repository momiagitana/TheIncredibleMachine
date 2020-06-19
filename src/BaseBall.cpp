#include "BaseBall.h"


BaseBall::BaseBall (const sf::Vector2f& center, bool movable, b2World &world)
    :Ball(center,ResourceManager::instance().getTexture(baseBall), movable, world, baseBall)
{
}


