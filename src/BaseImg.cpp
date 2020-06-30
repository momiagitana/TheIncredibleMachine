#include "baseImg.h"
#include <iostream>

BaseImg::BaseImg(sf::Vector2f center, Type_t objTexture)
{
	sf::Texture *texture = ResourceManager::instance().getTexture(objTexture);
	m_sprite.setTexture(*texture);
	m_sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
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
	//std::cout << loc.x << " " << loc.y << std::endl;
}

sf::Vector2f BaseImg::getSize() const
{
	return sf::Vector2f(m_sprite.getTextureRect().width, m_sprite.getTextureRect().height);
}

void BaseImg::setIntRect(sf::IntRect newRect)
{
	m_sprite.setTextureRect(newRect);
	m_sprite.setOrigin(getSize().x / 2, getSize().y / 2);
}

void BaseImg::setOrigin(float x, float y)
{
	m_sprite.setOrigin(x,y);
}

void BaseImg::setScale(float scale)
{
	m_sprite.setScale(sf::Vector2f(scale, scale));
}

void BaseImg::drawSmall (sf::RenderTexture& tinyBoard)
{
	auto pos = m_sprite.getPosition();
	auto scale = m_sprite.getScale();
	m_sprite.setScale(sf::Vector2f(BOARDS_RATIO_X,BOARDS_RATIO_Y));
	m_sprite.setPosition(sf::Vector2f(pos.x*BOARDS_RATIO_X, pos.y*BOARDS_RATIO_Y));
	tinyBoard.draw(m_sprite);
	m_sprite.setScale(scale);
	m_sprite.setPosition(pos);
}

void BaseImg::nextIntRect()
{
	sf::IntRect newRect = m_sprite.getTextureRect();
	if(newRect.left + newRect.width < m_sprite.getTexture()->getSize().x)
		newRect.left += newRect.width;

	setIntRect(newRect);
}

void BaseImg::prevIntRect()
{
	sf::IntRect newRect = m_sprite.getTextureRect();
	if (newRect.left - newRect.width >= 0)
		newRect.left -= newRect.width;

	setIntRect(newRect);

void BaseImg::setTextureRect(sf::IntRect intrect) //fix check if used
{
	m_sprite.setTextureRect(intrect);
}

const sf::IntRect& BaseImg::getTextureRect() const
{
	return m_sprite.getTextureRect();
}
