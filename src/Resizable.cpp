#include "Resizable.h"


Resizable::Resizable(const sf::Vector2f& center, const sf::Vector2u& size, sf::Texture* texture, bool movable, b2World &world, GameObject_t type)
    :GameObj(center, size, texture, false, movable, world, type)
{
}
