#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "globals.h"
#include "ResourceManager.h"

class PhysicsObj
{
private:

    b2Body*         m_body;
    b2FixtureDef    m_fixtureDef;
    b2Fixture*      m_fixture;

public:

    PhysicsObj(b2World &, const sf::Vector2f&, bool , Type_t);
    ~PhysicsObj();

    b2Vec2 getPosition() const { return  m_body->GetPosition(); }
    float getAngle() const { return m_body->GetAngle();}
    void setAngle(int whichAngle);
    void setPosition(sf::Vector2f);
    void setGravityScale(float);
    void setSize(sf::Vector2f);
    void applyForce(const b2Vec2&);
    int randomNumber(int min, int max);
    void setID(const int);
};
