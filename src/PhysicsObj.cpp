#include <PhysicsObj.h>


PhysicsObj::PhysicsObj(b2World &world, const sf::Vector2f& position, bool dynamic, Type_t type)
{
    b2BodyDef bodyDef;

	if (dynamic)
		bodyDef.type = b2_dynamicBody;
	else
		bodyDef.type = b2_staticBody;

    
    bodyDef.position.Set(position.x * MPP, position.y * MPP);
    m_body = world.CreateBody(&bodyDef);

	b2PolygonShape polygonShape;
    auto size = ResourceManager::instance().getTexture(type)->getSize();
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

void PhysicsObj::setAngle(int whichAngle)
{
    m_body->SetTransform( m_body->GetPosition(), whichAngle*45*DEG_TO_RAD);
}