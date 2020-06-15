#include "Ball.h"

Ball::Ball(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool movable, b2World &world)
    :GameObj(center, size, texture, true, movable, world)
{
}
