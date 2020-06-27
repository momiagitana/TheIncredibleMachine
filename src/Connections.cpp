#include "Connections.h"



Connections::Connections()
{
}

Connections::~Connections()
{
}

bool Connections::tryConnecting (std::shared_ptr<GameObj> obj)
{
    if (canConnect(obj.get()))
    {
        if (m_first == nullptr)
            m_first = obj.get();

        else 
            m_second = obj.get();
        
        return true;
    }
    m_first = nullptr;
    m_second = nullptr;

    return false;

}


bool Connections::canConnect(GameObj* obj) const
{
    if(obj != m_first)//fix set connected as soon as is m_first
        if (MouseEngine *engine = dynamic_cast<MouseEngine*>(obj))
            return !engine->isConected();

    return false;
}

bool Connections::doneConnecting()
{
    if (m_first != nullptr && m_second != nullptr) //fix
    {
        m_connections.push_back(std::make_pair(m_first, m_second));

        setConnectedStatus(m_first, true);
        setConnectedStatus(m_second, true);//fix conected

        m_first = m_second = nullptr;
        return true;
    }
    return false;
}

void Connections::checkConnections()
{
    for(auto &each : m_connections)
    {
        if(isOn(each.first))
            turnOn(each.second);
        else if (isOn(each.second))
            turnOn(each.first);
    }
}

bool Connections::isOn(GameObj* obj) const
{
    if (MouseEngine *engine = dynamic_cast<MouseEngine*>(obj))
        return engine->isOn();
}

void Connections::turnOn(GameObj* obj)
{
    if (MouseEngine *engine = dynamic_cast<MouseEngine*>(obj))
        engine->setStatus(true);//fix ON
}

void Connections::setConnectedStatus(GameObj* obj, bool status)
{
    if (MouseEngine *engine = dynamic_cast<MouseEngine*>(obj))
        engine->setConected(status);
}

void Connections::draw(sf::RenderWindow& window) const
{
    for (auto &each: m_connections)
        drawBelt(each, window);
}

void Connections::drawBelt(std::pair<GameObj*, GameObj*> each, sf::RenderWindow& window) const
{
    // sf::Vector2f loc1 = each.first->getLocation();
    // sf::Vector2f loc2 = each.second->getLocation();

    sf::Vertex line[2];
    line[0].position = each.first->getLocation();
    line[0].color  = sf::Color::Black;
    line[1].position = each.second->getLocation();
    line[1].color = sf::Color::Black;

    window.draw(line, 2, sf::Lines);

}

void Connections::unplug(GameObj* toUnplug)
{
    GameObj* other;
    auto i = 0;
    for (; i < m_connections.size() ; i++)
    {
        if (m_connections[i].first == toUnplug)
        {
            other = m_connections[i].second;
            break;
        }
        else if (m_connections[i].second == toUnplug)
        {
            other = m_connections[i].first;
            break;
        }
    }
    setConnectedStatus(toUnplug, false);
    setConnectedStatus(other, false);
    m_connections.erase(m_connections.begin() + i);
    m_first = other;
}

void Connections::reset()
{
    m_first = nullptr;
    m_second = nullptr; //not really necessary
}