#pragma once

#include "GameObj.h"
#include "Factory.h"//fix needs to add to base class


class Connectable : public GameObj
{
public:
    Connectable(const ObjInfo, const bool, b2World &, const int);
    ~Connectable();

    void backToStartingPlace(); //fix override
    Type_t handleClick(const sf::Vector2f); //fix override
    void setPosition(const sf::Vector2f);//override

    sf::Vector2f getConnectionButtonPos() const { return m_connection.getLocation(); }
    
    bool isConected()   const { return m_conected; }

    void setConected(const bool conected) { m_conected = conected; }

    void draw(sf::RenderWindow& window);

    void animation();


private:

    static bool m_registerit;

    bool m_conected = false; 

    Button m_connection;

    sf::Vector2f m_buttonDelta;

};

