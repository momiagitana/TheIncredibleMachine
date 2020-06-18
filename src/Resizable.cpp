#include "Resizable.h"


Resizable::Resizable(const sf::Vector2f& center, const sf::Vector2u& size, bool movable, b2World &world, GameObject_t type)
    :GameObj(center, size, false, movable, world, type)
{
}
