#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class PhysicsObj
{
private:

    b2Body*         m_body;
    b2FixtureDef    m_fixtureDef;
    b2Fixture*      m_fixture;
    
public:

    PhysicsObj(b2World &world, const sf::Vector2f& position, const sf::Vector2f& dimensions, bool dynamic);
    ~PhysicsObj();

    b2Vec2 getPosition() const { return  m_body->GetPosition(); }
    float getAngle() const { return m_body->GetAngle();}
    void setAngle(float angle);
    void setPosition(sf::Vector2f);
    void setGravityScale(float);
    void setSize(sf::Vector2f);
    void applyForce ();
    int randomNumber(int min, int max);


	float PPM = 64.f;
    float MPP = 0.015625f;

};
