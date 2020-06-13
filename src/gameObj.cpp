#include "gameObj.h"

GameObj::GameObj(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World &world)
	:BaseImg(center, size, texture), m_phyBody(world, center, size, dynamic) //change to center
{
}

void GameObj::draw (sf::RenderWindow& win)
{
	updateLoc();
	BaseImg::draw(win);
}

void GameObj::updateLoc()
{
	auto pos = m_phyBody.getPosition();
	BaseImg::setLocation(sf::Vector2f(pos.x,pos.y));
	BaseImg::setRotation(m_phyBody.getAngle());
}

// sf::Vector2f GameObj::metToPix(b2Vec2 pos)
// {

// 	return  sf::Vector2f(metToPix(pos.x), metToPix(pos.y));

// }

// float GameObj::metToPix(float met)
// {
//     return met / scaling;
// }

// bool GameObj::checkCollision(const sf::FloatRect& floatRect) const
// {
// 	//return true;
// 	return getGlobalBounds().intersects(floatRect);
// }
