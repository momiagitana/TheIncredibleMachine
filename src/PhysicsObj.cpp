#include <PhysicsObj.h>


PhysicsObj::PhysicsObj(b2World &world, const sf::Vector2f& center, const sf::Vector2f& size, bool dynamic)// float restitution)//, sf::Color color) 
{
  
	b2PolygonShape polygonShape;
    b2FixtureDef fixtureDef;
    b2BodyDef bodyDef;

	if (dynamic)
		bodyDef.type = b2_dynamicBody;
	else
		bodyDef.type = b2_staticBody;

    
    bodyDef.position.Set(center.x * MPP, center.y * MPP);
    m_body = world.CreateBody(&bodyDef);

    polygonShape.SetAsBox( size.x/2 * MPP, size.y/2 * MPP);
    fixtureDef.shape = &polygonShape;
    fixtureDef.friction = 1;
    fixtureDef.restitution	= 0.2f;
    fixtureDef.density	= 0.7f;

    m_body->CreateFixture(&fixtureDef);


}

PhysicsObj::~PhysicsObj()
{
}


void PhysicsObj::setPosition(sf::Vector2f pos)
{
    m_body->SetTransform(b2Vec2(pos.x * MPP, pos.y * MPP), 0.f);
}
