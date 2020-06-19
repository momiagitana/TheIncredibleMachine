#include "BaseImg.h"
#include <iostream>

BaseImg::BaseImg(sf::Vector2f center, sf::Texture* texture)
{
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin((*texture).getSize().x / 2, (*texture).getSize().y / 2);
	setSize(texture->getSize());
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

void BaseImg::setSize(sf::Vector2u size)
{
	m_sprite.scale((size.x / m_sprite.getGlobalBounds().width), (size.y / m_sprite.getGlobalBounds().height));
}

void BaseImg::setposition(sf::Vector2f loc)
{
	m_sprite.setPosition(loc);
	std::cout << loc.x << " " << loc.y << std::endl;
}



sf::Vector2f BaseImg::getSize() const
{
	return sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().height);
}

void BaseImg::setIntRect(sf::IntRect newRect)
{
	m_sprite.setTextureRect(newRect);
	m_sprite.setOrigin(getSize().x/2, getSize().y/2);
}
