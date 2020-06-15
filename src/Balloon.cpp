#include "Balloon.h"


Balloon::Balloon(const sf::Vector2f& center, bool movable, b2World &world)
    :GameObj(center, sf::Vector2f(30.f,50.f), ResourceManager::instance().getTexture(ResourceManager::Texture::balloon), true, movable, world)
{
}
