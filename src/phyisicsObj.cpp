#include <PhyisicsObj.h>


PhyisicsObj::PhyisicsObj()
{
}

PhyisicsObj::~PhyisicsObj()
{
}


void PhyisicsObj::init(b2World* world, const sf::Vector2f& position, const sf::Vector2f& dimensions)//, sf::Color color) 
{
    m_dimensions = dimensions;
    //m_color = color;
    // Make the body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    m_body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(dimensions.x / 2.0f, dimensions.y / 2.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    m_fixture = m_body->CreateFixture(&fixtureDef);
}