#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class PhyisicsObj
{
private:


    b2Body* m_body;
    b2BodyDef* m_bodyDef;
    b2Fixture* m_fixture;

   
public:

    PhyisicsObj(b2World* world, const sf::Vector2f& position, const sf::Vector2f& dimensions, bool dynamic);
    ~PhyisicsObj();

    b2Vec2 getPosition() const { return  m_body->GetPosition(); }
    float getAngle() const { return m_body->GetAngle();}
    //b2Fixture* getFixture() const { return m_fixture; }

 
};
