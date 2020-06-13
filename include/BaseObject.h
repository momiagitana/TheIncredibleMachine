#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"




class BaseObject
{
public:

	BaseObject(const std::shared_ptr<sf::Texture>& texture, sf::Vector2f, sf::Vector2f);
	virtual ~BaseObject();
	sf::FloatRect getGlobalBounds()const;
	virtual void draw(sf::RenderWindow&);
	void setIntRect(sf::IntRect);
	void fixSize();
	bool checkCollision(const sf::FloatRect& floatRect) const;
	void setscale(sf::Vector2f newscale);
	void setTexture(const sf::Texture* texture);
	void setfillcolor(sf::Color color);
	void setorigin(sf::Vector2f origin);
	void setposition(sf::Vector2f location);
	sf::Vector2f getscale();

protected:

	sf::Sprite m_sprite;
	sf::Vector2f m_size;
};
