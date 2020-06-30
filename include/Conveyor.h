#pragma once
#include "Factory.h"//fix needs to add to base class
#include "Connectable.h"

class Conveyor : public Connectable
{
public:
	Conveyor (ObjInfo info, bool movable, b2World &world);

	//void draw (sf::RenderWindow&);
	
private:
	static bool m_registerit;
};
