#pragma once
#include "GameObj.h"
#include "MouseEngine.h"


class Connections
{
private:
    std::vector<std::pair<GameObj*, GameObj*>> m_connections;

    GameObj* m_first = nullptr;
    GameObj* m_second = nullptr;
    sf::Vector2f  m_mousePos;

    bool canConnect(GameObj*) const;
    void setConnectedStatus(GameObj* obj, bool status);
    void drawBelt(std::pair<GameObj*, GameObj*>, sf::RenderWindow&) const;
    void drawMovingBelt(sf::RenderWindow &) const;

public:
    Connections();
    ~Connections();


    bool tryConnecting (std::shared_ptr<GameObj>);
    bool doneConnecting();
    void checkConnections();
    bool isOn(GameObj*) const;
    void turnOn(GameObj*); 
    void draw (sf::RenderWindow&) const;
    void unplug (GameObj*);
    void reset();
    void setMousePos(sf::Vector2f mouseLoc);
};
