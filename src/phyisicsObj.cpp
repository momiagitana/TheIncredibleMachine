#include <PhyisicsObj.h>


PhyisicsObj::PhyisicsObj(b2World* world, const sf::Vector2f& position, const sf::Vector2f& dimensions, bool dynamic)//, sf::Color color) 
{
  
    m_bodyDef =  new b2BodyDef();
	if (dynamic)
		m_bodyDef->type = b2_dynamicBody;
	else
		m_bodyDef->type = b2_staticBody;


	m_bodyDef->position.Set(position.x, position.y);
	m_body = world->CreateBody(m_bodyDef);

	b2PolygonShape* shape = new b2PolygonShape();
	shape->SetAsBox(dimensions.x * 0.5f - b2_polygonRadius, dimensions.y * 0.5f - b2_polygonRadius);


    b2FixtureDef fixtureDef;
    fixtureDef.shape = shape;

    

	if (dynamic)
	{
    	fixtureDef.density = 1.0f;
    	fixtureDef.friction = 0.3f;
		m_body->CreateFixture(&fixtureDef);
	}
	else
		m_body->CreateFixture(shape, 0);

}

PhyisicsObj::~PhyisicsObj()
{
}