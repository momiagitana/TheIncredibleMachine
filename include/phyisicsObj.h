#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class PhyisicsObj
{
private:


    std::unique_ptr<b2Body> m_body;
    std::unique_ptr<b2BodyDef> m_bodyDef;
    std::unique_ptr<b2Fixture> m_fixture;

    //sf::Color m_color;
   
public:

    PhyisicsObj(b2World* world, const sf::Vector2f& position, const sf::Vector2f& dimensions, bool dynamic);
    ~PhyisicsObj();

    b2Vec2 getPosition() const { return  m_body->GetPosition(); }
    //b2Fixture* getFixture() const { return m_fixture; }

 
};
