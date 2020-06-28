#pragma once

#include "GameObj.h"
#include "Factory.h"//fix needs to add to base class


class Connectable : public GameObj
{
public:
    Connectable(ObjInfo info, bool movable, b2World &world, int);
    ~Connectable();

    Type_t handleClick(sf::Vector2f); //fix override
    void setPosition(sf::Vector2f);//override

    sf::Vector2f getConnectionButtonPos() const { return m_connection.getLocation(); }
    
    bool isConected()   const { return m_conected; }
    bool isOn()         const { return m_status; }

    void setConected(bool conected) { m_conected = conected; }
    void setStatus(bool status)     { m_status = status; }

private:

    static bool m_registerit;

    bool m_conected = false; 
    bool m_status = false; //fix ON OFF

    Button m_connection;

    sf::Vector2f m_buttonDelta;

};

