#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "PhysicsObj.h"


class GameObj : public Button
{
public:


	GameObj(const sf::Vector2f& center, const sf::Vector2u& size, bool dynamic, bool movable, b2World &world, GameObject_t);

	virtual ~GameObj(){}

	void draw (sf::RenderWindow&);

	void setInitialLoc();

	void setGravityScale(float);

	GameObject_t getType() const;

	int getID() const { return m_ID; }

	bool isMovable() const { return m_movable; }

	void updateBodySize();

	void rotateBody(float angle);

	PhysicsObj getPhysical()
	{
		return m_phyObj;
	}

private:

	PhysicsObj m_phyObj;
	bool m_movable;
	int m_ID;
	sf::Vector2f m_initialLoc;
	GameObject_t m_type;
	
	void updateLoc();

	
};
