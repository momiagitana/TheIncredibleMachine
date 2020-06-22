#include <PhysicsObj.h>


PhysicsObj::PhysicsObj(b2World &world, const sf::Vector2f& center, const sf::Vector2f& size, bool dynamic)// float restitution)//, sf::Color color) 
{
    b2BodyDef bodyDef;

	if (dynamic)
		bodyDef.type = b2_dynamicBody;
	else
		bodyDef.type = b2_staticBody;
  
    bodyDef.position.Set(center.x * MPP, center.y * MPP);
    m_body = world.CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
    polygonShape.SetAsBox( size.x/2 * MPP, size.y/2 * MPP);
    m_fixtureDef.shape = &polygonShape;
    m_fixtureDef.friction = 1;
    m_fixtureDef.restitution=0.4f;
    m_fixtureDef.density=0.7f;

    m_fixture = m_body->CreateFixture(&m_fixtureDef);
    
}

PhysicsObj::~PhysicsObj()
{
    m_body->GetWorld()->DestroyBody(m_body);
}


void PhysicsObj::setPosition(sf::Vector2f pos)
{
    m_body->SetTransform(b2Vec2(pos.x * MPP, pos.y * MPP), 0.f);
    m_body->SetLinearVelocity(b2Vec2(0, 0));
    m_body->SetAngularVelocity(0);
    m_body->SetAwake(true);
}

void PhysicsObj::setGravityScale(float scale)
{
    // m_fixtureDef.density = mass; //this fixture is attached to body below
    // m_body->ResetMassData();
    m_body->SetGravityScale(scale);

}

void PhysicsObj::setSize(sf::Vector2f size)
{
    m_body->DestroyFixture(m_fixture);

  
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox( size.x/2 * MPP, size.y/2 * MPP);
    m_fixtureDef.shape = &polygonShape;
    m_fixtureDef.friction = 1;
    m_fixtureDef.restitution = 0.4f;
    m_fixtureDef.density = 0.7f;
    m_fixture = m_body->CreateFixture(&m_fixtureDef);

}

void PhysicsObj::setAngle(float angle)
{
    m_body->SetTransform( m_body->GetPosition(), m_body->GetAngle()+angle);
}

void PhysicsObj::applyForce()
{
    b2Vec2 force;
    force.x = 200;
    force.y = 200;
    //m_body = vectorShapes.back()->getBody();
    
    m_body->ApplyForceToCenter(force, true);

}

int PhysicsObj::randomNumber(int min, int max)
{
    return min + rand()% (max - min + 1);
}