#include "BaseObject.h"

BaseObject::BaseObject(const std::shared_ptr<sf::Texture>&texture, sf::Vector2f location, sf::Vector2f size) :m_size(size)
{
	m_sprite.setPosition(location);

	if (texture)
		m_sprite.setTexture(*texture);

	fixSize();
}

BaseObject::~BaseObject() {}

sf::FloatRect BaseObject::getGlobalBounds()const
{
	return m_sprite.getGlobalBounds();
	
}

void BaseObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void BaseObject::setIntRect(sf::IntRect intRect)
{
	m_sprite.setTextureRect(intRect);
}

void BaseObject::fixSize()
{
	m_sprite.scale((m_size.x / m_sprite.getGlobalBounds().width), (m_size.y / m_sprite.getGlobalBounds().height));
}

bool BaseObject::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_sprite.getGlobalBounds().intersects(floatRect);
}

void BaseObject::setscale(sf::Vector2f newscale)
{
	m_sprite.setScale(newscale);
}

void BaseObject::setTexture(const sf::Texture* texture)
{
	m_sprite.setTexture(*texture);
}

void BaseObject::setfillcolor(sf::Color color)
{
	m_sprite.setColor(color);
}

void BaseObject::setorigin(sf::Vector2f origin)
{
	m_sprite.setOrigin(origin.x,origin.y);
}

void BaseObject::setposition(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

sf::Vector2f BaseObject::getscale()
{
	return m_sprite.getScale();
}

