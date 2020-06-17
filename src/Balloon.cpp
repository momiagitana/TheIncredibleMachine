#include "Balloon.h"


Balloon::Balloon(const sf::Vector2f& center, bool movable, b2World &world)
    :GameObj(center, sf::Vector2f(32.f,47.f), ResourceManager::instance().getTexture(balloon), true, movable, world)
{
    setGravityScale(-0.3);
    //updateTexture(sf::IntRect(sf::Vector2i(9,12),sf::Vector2i(32,47)));
}
