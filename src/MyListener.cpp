#include"MyListener.h"


void MyListener::BeginContact(b2Contact* contact)
{
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    b2Body* body1 = fixtureA->GetBody();
    b2Body* body2 = fixtureB->GetBody();
    std::cout << "started";
}

void MyListener::EndContact(b2Contact* contact)
{
}

void MyListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
    std::cout << "colide";
}
