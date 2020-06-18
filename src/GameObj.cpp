#include "GameObj.h"

GameObj::GameObj(const sf::Vector2f& center, const sf::Vector2u& size, bool dynamic, bool movable, b2World &world, GameObject_t type)
	:Button(center, type), m_phyObj(world, center, sf::Vector2f(size.x,size.y), dynamic), m_movable(movable), m_initialLoc(center), m_type(type)
{
	static int ID = 0;
	m_ID = ID;
	ID ++;
	updateLoc();
}

void GameObj::draw (sf::RenderWindow& win)
{
	updateLoc();
	BaseImg::draw(win);
}

void GameObj::updateLoc()
{
	auto pos = m_phyObj.getPosition();
	BaseImg::setLocation(sf::Vector2f(pos.x,pos.y));
	BaseImg::setRotation(m_phyObj.getAngle());
}


void GameObj::setInitialLoc()
{
	m_phyObj.setPosition(m_initialLoc);
	updateLoc();
}

void GameObj::setGravityScale(float scale)
{
	m_phyObj.setGravityScale(scale);
}

GameObject_t GameObj::getType() const
{
	return m_type;
}