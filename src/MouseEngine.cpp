#include "MouseEngine.h"

MouseEngine::MouseEngine(const ObjInfo info, const bool movable, b2World &world)
    :Connectable(info, movable, world, 0)//fix pass data on info
{
    setIntRect(sf::IntRect(0,0,48,32));//fix
    updateBodySize();
}

MouseEngine::~MouseEngine()
{
}

bool MouseEngine::m_registerit = ObjFactory::registerit(mouseEngine, [](const ObjInfo info, const bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<MouseEngine>(info,movable,world); });




void MouseEngine::setStatus(const bool status)
{
    GameObj::setStatus(status);

    if(status)
        ResourceManager::instance().playSFXengine();
    else
        ResourceManager::instance().stopSFXengine();

}