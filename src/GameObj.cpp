#include "GameObj.h"

GameObj::GameObj(const sf::Vector2f& center, bool dynamic, bool movable, b2World &world, Type_t type)
	:Button(center, type), m_phyObj(world, center, dynamic, type), m_movable(movable), m_initialLoc(center)
{
	static int ID = 0;
	m_ID = ID;
	ID ++;
	updateLoc();
}

void GameObj::draw (sf::RenderWindow& win, bool running)
{
	if (running)
		updateLoc();
	BaseImg::draw(win);
}

void GameObj::updateLoc()
{
	auto pos = m_phyObj.getPosition();
	BaseImg::setPosition(sf::Vector2f(pos.x * PPM, pos.y * PPM));
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

void GameObj::updateBodySize()
{
	m_phyObj.setSize(BaseImg::getSize());
}

void GameObj::rotateBody(float angle)
{
	m_phyObj.setAngle(angle);
	BaseImg::setRotation(m_phyObj.getAngle());
}