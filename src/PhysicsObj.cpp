#include <PhysicsObj.h>


PhysicsObj::PhysicsObj(b2World &world, const sf::Vector2f& position, bool dynamic, Type_t type)
{
    auto objPhysicsInfo = physicsInfo[int(type)];
    b2BodyDef bodyDef;
    b2PolygonShape polygonShape;
    b2CircleShape circleShape;

	if (dynamic)
		bodyDef.type = b2_dynamicBody;
	else
		bodyDef.type = b2_staticBody;
    
    bodyDef.position.Set(position.x * MPP, position.y * MPP);

    m_body = world.CreateBody(&bodyDef);
    auto size = ResourceManager::instance().getTexture(type)->getSize();

    if (objPhysicsInfo._shape == RECT)
    {
        polygonShape.SetAsBox(size.x / 2 * MPP, size.y / 2 * MPP);
        m_fixtureDef.shape = &polygonShape;
    }
    else if (objPhysicsInfo._shape == CIRCLE)
    {
        circleShape.m_radius = size.x / 2 * MPP;
        m_fixtureDef.shape = &circleShape;
    }
    
    m_fixtureDef.friction = objPhysicsInfo._friction;
    m_fixtureDef.restitution = objPhysicsInfo._restitution;
    m_fixtureDef.density = objPhysicsInfo._density;
    m_fixture = m_body->CreateFixture(&m_fixtureDef);

    //m_body->SetUserData();
}

PhysicsObj::~PhysicsObj()
{
    m_body->GetWorld()->DestroyBody(m_body);
}

void PhysicsObj::setID(const int ID)
{
    m_body->SetUserData((void*)ID);
}

void PhysicsObj::setPosition(sf::Vector2f pos)
{
    auto angle = m_body->GetAngle();
    if(m_body->GetType() == b2BodyType::b2_dynamicBody)
        angle = 0;

    m_body->SetTransform(b2Vec2(pos.x * MPP, pos.y * MPP), angle);
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

//     m_body->SetTransform( m_body->GetPosition(), m_body->GetAngle()+angle);
// }

// void PhysicsObj::applyForce()
// {
//     b2Vec2 force;
//     force.x = 200;
//     force.y = 200;
//     //m_body = vectorShapes.back()->getBody();
    
//     m_body->ApplyForceToCenter(force, true);

// }

// int PhysicsObj::randomNumber(int min, int max)
// {
//     return min + rand()% (max - min + 1);

    m_body->SetTransform( m_body->GetPosition(), whichAngle*45*DEG_TO_RAD);

}