#pragma once
#include "GameObj.h"
#include "Factory.h"//fix needs to add to base class


class MouseEngine : public GameObj
{
public:
    MouseEngine(ObjInfo info, bool movable, b2World &world);
    ~MouseEngine();

    Type_t mouseOnMe(sf::Vector2f);
    void setPosition(sf::Vector2f) ;//override
    
    bool isConected() const { return m_conected; }
    bool isOn() const       { return m_status; }

    void setConected    (bool conected) { m_conected = conected; }
    void setStatus      (bool status)   { m_status = status; }

private:
    static bool m_registerit;

    bool m_conected = false; 
    bool m_status = false; //fix ON OFF

    Button m_conection;
    

};

