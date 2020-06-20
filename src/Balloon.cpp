#include "Balloon.h"


Balloon::Balloon(const sf::Vector2f& center, bool movable, b2World &world)
    :GameObj(center, true, movable, world, balloon)
{
    setGravityScale(-0.3);
}
