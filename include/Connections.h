#pragma once
#include "GameObj.h"
#include "Connectable.h"


class Connections
{
private:
    std::vector<std::pair<Connectable*, Connectable*>> m_connections;

    Connectable* m_first = nullptr;
    Connectable* m_second = nullptr;
    sf::Vector2f  m_mousePos;

    Connectable* canConnect(GameObj*) const;
    void setConnectedStatus(Connectable* obj, bool status);
    void drawBelt(std::pair<Connectable*, Connectable*>, sf::RenderWindow&) const;
    void drawMovingBelt(sf::RenderWindow &) const;

public:
    Connections();
    ~Connections();

    bool isOn(Connectable*) const; //fix private?
    void turnOn(Connectable*); 

    bool tryConnecting (std::shared_ptr<GameObj>);
    bool doneConnecting();
    void checkConnections();
    void draw (sf::RenderWindow&) const;
    void unplug (Connectable*);
    void reset();
    void setMousePos(sf::Vector2f mouseLoc);
    void deleteConnection(Connectable* obj);
    sf::Vector2f calculateNormal(const sf::Vertex&, const sf::Vertex&)const;
    Connectable* isConnectedAndConnectable(GameObj* obj)const;
};
