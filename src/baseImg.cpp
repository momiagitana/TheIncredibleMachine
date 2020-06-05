#include "baseImg.h"


BaseImg::BaseImg(sf::Vector2f topLeft, sf::Vector2f size, sf::Texture* texture)
{
	m_sprite.setPosition(topLeft);

	if (texture != (sf::Texture*)NULL)
		m_sprite.setTexture(*texture);

	setSize(size);
}

sf::FloatRect BaseImg::getGlobalBounds() const
{
	return m_sprite.getGlobalBounds();
}

void BaseImg::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void BaseImg::setLocation(sf::Vector2f topLeft)
{
	m_sprite.setPosition(topLeft);
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

// void BaseImg::updateTexture(sf::IntRect newRect)
// {
// 	m_sprite.setTextureRect(newRect);
// }


