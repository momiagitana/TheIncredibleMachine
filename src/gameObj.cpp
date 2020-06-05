#include "gameObj.h"

GameObj::GameObj(const sf::Vector2f& topLeft, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World* world)
	:BaseImg(topLeft, size, texture), m_body(world, topLeft, size, dynamic) //change to center
{
}



// bool GameObj::checkCollision(const sf::FloatRect& floatRect) const
// {
// 	//return true;
// 	return getGlobalBounds().intersects(floatRect);
// }
