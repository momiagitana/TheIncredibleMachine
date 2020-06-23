#include "BasketBall.h"


BasketBall::BasketBall (const sf::Vector2f& center, bool movable, b2World &world)
    :Ball(center, movable, world, basketBall)
{
}

bool BasketBall::m_registerit = ObjFactory::registerit(basketBall, [](const sf::Vector2f& center, bool movable, b2World &world) -> std::unique_ptr<GameObj> { return std::make_unique<BasketBall>(center,movable,world); });