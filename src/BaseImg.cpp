#include "BaseImg.h"


BaseImg::BaseImg(sf::Vector2f center, sf::Vector2f size, sf::Texture* texture)
{

	m_sprite.setTexture(*texture);
	m_sprite.setOrigin((*texture).getSize().x/2, (*texture).getSize().y/2);
	setSize(size);
	//setLocation(center);
}

void BaseImg::setRotation(float angle)
{
	m_sprite.setRotation((angle * 180) / 3.14);
}

sf::FloatRect BaseImg::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

void BaseImg::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void BaseImg::setLocation(sf::Vector2f center)
{
	m_sprite.setPosition(center.x * PPM, center.y * PPM);

}

sf::Vector2f BaseImg::getLocation() const
{
	return m_sprite.getPosition();
}

void BaseImg::setColor(sf::Color color)
{
	m_sprite.setColor(color);
}

void BaseImg::setSize(sf::Vector2f size)
{
	m_sprite.scale((size.x / m_sprite.getGlobalBounds().width), (size.y / m_sprite.getGlobalBounds().height));
}

sf::Vector2f BaseImg::getSize() const
{
	return sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height); 
}
// void BaseImg::updateTexture(sf::IntRect newRect)
// {
// 	m_sprite.setTextureRect(newRect);
// }


