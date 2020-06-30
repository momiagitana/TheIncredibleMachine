#include "MouseEngine.h"

MouseEngine::MouseEngine(ObjInfo info, bool movable, b2World &world)
    :Connectable(info, movable, world, 0)//fix pass data on info
{
    setIntRect(sf::IntRect(0,0,48,32));//fix
    updateBodySize();
}

MouseEngine::~MouseEngine()
{
}

bool MouseEngine::m_registerit = ObjFactory::registerit(mouseEngine, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<MouseEngine>(info,movable,world); });