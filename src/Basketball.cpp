#include "BasketBall.h"

BasketBall::BasketBall (const sf::Vector2f& center, bool movable, b2World &world)
    :Ball(center,sf::Vector2f(40.f,40.f),ResourceManager::instance().getTexture(ResourceManager::Texture::basketBall), movable, world)
{
}
