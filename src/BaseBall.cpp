#include "BaseBall.h"


BaseBall::BaseBall (const sf::Vector2f& center, bool movable, b2World &world)
    :Ball(center, movable, world, baseBall)
{
}


bool BaseBall::m_registerit = ObjFactory::registerit(baseBall, 
    [](const sf::Vector2f& center, bool movable, b2World &world) 
    -> std::shared_ptr<GameObj> { return std::make_shared<BaseBall>(center,movable,world); });