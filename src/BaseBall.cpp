#include "BaseBall.h"

BaseBall::BaseBall (const sf::Vector2f& center, b2World &world)
    :Ball(center,sf::Vector2f(25.f,25.f),ResourceManager::instance().getTexture(ResourceManager::Texture::baseBall), world)
{
}


