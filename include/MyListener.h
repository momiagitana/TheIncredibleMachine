#pragma once
#include <box2d/box2d.h>
#include <iostream>
class MyListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact);
   
    void EndContact(b2Contact* contact);
    virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
};