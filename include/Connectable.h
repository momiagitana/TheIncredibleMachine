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
    void setConected(bool conected) { m_conected = conected; }

private:
    static bool m_registerit;

    bool m_conected = false; 

    Button m_connection;

    sf::Vector2f m_buttonDelta;
    

};

