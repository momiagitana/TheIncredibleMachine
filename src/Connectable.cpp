#include "Connectable.h"


Connectable::Connectable(ObjInfo info, bool movable, b2World &world, int typeOfEngine)//fix pass int on ObjInfo
    :GameObj(info._loc, STATIC, movable, world, info._typ),
    m_connection((sf::Vector2f(info._loc.x, info._loc.y)), connectButton)
{
    m_buttonDelta = sf::Vector2f(DELTA_ENGINE_CONECT[typeOfEngine][0],DELTA_ENGINE_CONECT[typeOfEngine][1]);
    setPosition(info._loc);
}

Connectable::~Connectable()
{
}

void Connectable::setPosition(sf::Vector2f loc)
{
    GameObj::setPosition(loc);
    m_connection.setPosition(sf::Vector2f(loc.x + m_buttonDelta.x, loc.y + m_buttonDelta.y));
}


Type_t Connectable::handleClick(sf::Vector2f loc)
{
    if(m_connection.mouseOnMe(loc))
        return m_connection.getType();

    return getType();
}


void Connectable::backToStartingPlace()
{
    GameObj::backToStartingPlace();
    m_status = false;
}