#include "Ball.h"

Ball::Ball(const sf::Vector2f& center, sf::Texture* texture, bool movable, b2World &world, GameObject_t type)
    :GameObj(center, texture->getSize(), texture, true, movable, world, type)
{
}
