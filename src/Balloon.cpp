#include "Balloon.h"


Balloon::Balloon(const sf::Vector2f& center, bool movable, b2World &world)
    :GameObj(center, ResourceManager::instance().getTexture(balloon)->getSize(), true, movable, world, balloon)
{
    setGravityScale(-0.3);
    //updateTexture(sf::IntRect(sf::Vector2i(9,12),sf::Vector2i(32,47)));
}
