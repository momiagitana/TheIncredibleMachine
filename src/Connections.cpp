#include "Connections.h"



Connections::Connections()
{
}

Connections::~Connections()
{
}

bool Connections::tryConnecting (std::shared_ptr<GameObj> obj)
{
    if (Connectable* toAdd = canConnect(obj.get()))//fix check that if null doestn enter
    {
        if (m_first == nullptr)
            m_first = toAdd;

        else 
            m_second = toAdd;
        
        return true;
    }
    m_first = nullptr;
    m_second = nullptr;

    return false;

}

Connectable* Connections::isConnectedAndConnectable(GameObj* obj) const //fix kefel code
{
    if (Connectable* connectable = dynamic_cast<Connectable*>(obj))
        if(connectable->isConected())
            return connectable;

    return nullptr;
}

Connectable* Connections::canConnect(GameObj* obj) const
{
    if(obj != m_first)//fix set connected as soon as is m_first
        if (Connectable* connectable = dynamic_cast<Connectable*>(obj))
            if(!connectable->isConected())
                return connectable;

    return nullptr;
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

bool Connections::isOn(Connectable* connectable) const
{
    return connectable->isOn();
}

void Connections::turnOn(Connectable* connectable)
{
    connectable->setStatus(true);//fix ON
}

void Connections::setConnectedStatus(Connectable* connectable, bool status)
{
    connectable->setConected(status);
}

void Connections::draw(sf::RenderWindow& window) const
{
    for (auto &each: m_connections)
        drawBelt(each, window);

    if (m_first != nullptr)//fix
        drawMovingBelt(window);
}

void Connections::drawBelt(std::pair<Connectable*, Connectable*> each, sf::RenderWindow& window) const
{
    sf::Vertex line[2];
    line[0].position = each.first->getConnectionButtonPos();
    line[0].color  = sf::Color::Black;
    line[1].position = each.second->getConnectionButtonPos();
    line[1].color = sf::Color::Black;

    window.draw(line, 2, sf::Lines);
}

void Connections::unplug(Connectable* toUnplug)
{
    Connectable* other;
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

void Connections::setMousePos(sf::Vector2f mouseLoc)
{
    m_mousePos = mouseLoc;
}

void Connections::drawMovingBelt(sf::RenderWindow &window) const
{
    sf::Vertex line[2];
    line[0].position = m_first->getConnectionButtonPos();
    line[0].color  = sf::Color::Black;
    line[1].position = m_mousePos;
    line[1].color = sf::Color::Black;

    window.draw(line, 2, sf::Lines);
}

void Connections::deleteConnection(Connectable* obj)
{
    Connectable* other;
    auto i = 0;
    for (; i < m_connections.size() ; i++) //fix code repeated
    {
        if (m_connections[i].first == obj)
        {
            other = m_connections[i].second;
            break;
        }
        else if (m_connections[i].second == obj)
        {
            other = m_connections[i].first;
            break;
        }
    }
    setConnectedStatus(obj, false);
    setConnectedStatus(other, false);
    m_connections.erase(m_connections.begin() + i);
}