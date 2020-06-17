#include "BasketBall.h"


BasketBall::BasketBall (const sf::Vector2f& center, bool movable, b2World &world)
    :Ball(center,ResourceManager::instance().getTexture(basketBall), movable, world, basketBall)
{
}
