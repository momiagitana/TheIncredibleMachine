#include "BasketBall.h"


BasketBall::BasketBall (const sf::Vector2f& center, bool movable, b2World &world)
    :Ball(center, movable, world, basketBall)
{
}
