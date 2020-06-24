#pragma once
#include"Resizable.h"
#include "Factory.h"//fix needs to add to base class


class Conveyor : public Resizable
{
public:
	Conveyor (const sf::Vector2f& center, bool movable, b2World &world);
	
private:
	static bool m_registerit;
};
