#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "PhysicsObj.h"


class GameObj : public Button
{
public:


	GameObj(const sf::Vector2f&, bool, bool, b2World &, Type_t);

	~GameObj(){}
	void draw (sf::RenderWindow&, bool);
	void setInitialLoc();
	void setGravityScale(float);
	int getID() const { return m_ID; }
	bool isMovable() const { return m_movable; }
	void updateBodySize();
	void rotateBody(float angle);
	ObjInfo getInfo();

private:

	PhysicsObj m_phyObj;
	bool m_movable;
	int m_ID;
	sf::Vector2f m_initialLoc;
	
	void updateLoc();

	
};
