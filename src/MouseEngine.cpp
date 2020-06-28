#include "MouseEngine.h"

MouseEngine::MouseEngine(ObjInfo info, bool movable, b2World &world)
    :GameObj(info._loc, STATIC, movable, world, mouseEngine),
     m_connection((sf::Vector2f(info._loc.x + DELTA_ENGINE_CONECT[0][0], info._loc.y + DELTA_ENGINE_CONECT[0][1])), connectButton)
{

}

MouseEngine::~MouseEngine()
{
}

// void MouseEngine::draw(sf::RenderWindow& win) const
// {
//     BaseImg::draw(win);
//     m_engineConect.draw(win);
// }

void MouseEngine::setPosition(sf::Vector2f loc)
{
    GameObj::setPosition(loc);
    m_connection.setPosition(sf::Vector2f(loc.x + DELTA_ENGINE_CONECT[0][0], loc.y + DELTA_ENGINE_CONECT[0][1]));
}


Type_t MouseEngine::handleClick(sf::Vector2f loc)
{
    if(m_connection.mouseOnMe(loc))
        return m_connection.getType();

    return getType();
}


bool MouseEngine::m_registerit = ObjFactory::registerit(mouseEngine, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<MouseEngine>(info,movable,world); });