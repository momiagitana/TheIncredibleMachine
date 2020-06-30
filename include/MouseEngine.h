#pragma once
#include "GameObj.h"
#include "Factory.h"//fix needs to add to base class
#include "Connectable.h"


class MouseEngine : public Connectable
{
public:
    MouseEngine(ObjInfo info, bool movable, b2World &world);
    ~MouseEngine();


private:
    static bool m_registerit;
};

