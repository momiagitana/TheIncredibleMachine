#include "BasketBall.h"

BasketBall::BasketBall (const sf::Vector2f& center, b2World &world)
    :Ball(center,sf::Vector2f(40.f,40.f),ResourceManager::instance().getTexture(GameObject_t::basketBall), world)
{
}
