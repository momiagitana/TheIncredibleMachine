#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "PhysicsObj.h"
#include "CollisionsSFML.h"


class GameObj : public Button
{
public:

	GameObj(const sf::Vector2f&, const bool, bool, b2World &, Type_t);

	virtual ~GameObj(){}


	virtual void backToStartingPlace();

	void setGravityScale(float);
	int getID() const { return m_ID; }
	bool isMovable() const { return m_movable; }
	void updateBodySize();
	virtual ObjInfo getInfo() const; 
	void rotateBody(int);
	void updateLoc();

	//for collisions
	int aboveOrBelow(GameObj& other) const;
	bool isBelow(GameObj& other) const;

	void wakeUp();

	void setMouse(bool onMe) { m_mouseOnMe = onMe; } 
	bool getMouseOverMe() const { return m_mouseOnMe; }

	virtual void setPosition(sf::Vector2f);
	virtual void setInitialLoc();

	void applyForce(const b2Vec2& force) { m_phyObj.applyForce(force); }

	bool pixelPerfectColides(GameObj&) const;

private:

	PhysicsObj m_phyObj;
	bool m_movable;
	int m_ID;
	sf::Vector2f m_initialLoc;
	bool m_mouseOnMe = false;
	
};
