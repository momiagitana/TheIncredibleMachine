#include "gameObj.h"

GameObj::GameObj(const sf::Vector2f& topLeft, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World* world)
	:BaseImg(topLeft, size, texture), m_body(world, topLeft, size, dynamic) //change to center
{
}

void GameObj::draw (sf::RenderWindow& win)
{
	updateLoc();
	BaseImg::draw(win);
}

void GameObj::updateLoc()
{
	auto pos = m_body.getPosition();
	BaseImg::setLocation(sf::Vector2f(pos.x,pos.y));
}

// bool GameObj::checkCollision(const sf::FloatRect& floatRect) const
// {
// 	//return true;
// 	return getGlobalBounds().intersects(floatRect);
// }
