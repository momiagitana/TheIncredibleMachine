#include "Ball.h"

Ball::Ball(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, b2World &world)
    :GameObj(center, size, texture, true, world)
{
}
