#include "GameObj.h"

GameObj::GameObj(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World &world)
	:BaseImg(center, size, texture), m_phyObj(world, center, size, dynamic)
{
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
