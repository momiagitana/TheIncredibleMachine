#include "Ball.h"

Ball::Ball(const sf::Vector2f& center, bool movable, b2World &world, Type_t type)
    :GameObj(center, true, movable, world, type)
{
}
