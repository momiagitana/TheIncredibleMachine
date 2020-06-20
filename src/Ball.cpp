#include "Ball.h"

Ball::Ball(const sf::Vector2f& center, const sf::Vector2u& size, bool movable, b2World &world, GameObject_t type)
    :GameObj(center, size, true, movable, world, type)
{
}
