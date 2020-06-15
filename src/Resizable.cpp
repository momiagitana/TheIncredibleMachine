#include "Resizable.h"


Resizable::Resizable(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, int which, bool movable, b2World &world)
    :GameObj(center, size, texture, true, movable, world) m_which(which)
{
}
