#include "baseImg.h"
#include <iostream>

BaseImg::BaseImg(sf::Vector2f center, Type_t objTexture)
{
	sf::Texture *texture = ResourceManager::instance().getTexture(objTexture);
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
	//setSize(texture->getSize());
	setPosition(center);
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

void BaseImg::setPosition(sf::Vector2f loc)
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
}

void BaseImg::setOrigin(float x, float y)
{
	m_sprite.setOrigin(x,y);
}

void BaseImg::setScale(float scale)
{
	m_sprite.setScale(sf::Vector2f(scale, scale));
}

void BaseImg::setTextureRect(sf::IntRect intrect)
{
	m_sprite.setTextureRect(intrect);
}

const sf::IntRect& BaseImg::getTextureRect() const
{
	return m_sprite.getTextureRect();
}
