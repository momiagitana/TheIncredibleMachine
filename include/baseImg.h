#pragma once

#include <SFML/Graphics.hpp>
#include <globals.h>


class BaseImg
{
public:

	BaseImg(sf::Vector2f, sf::Vector2f, sf::Texture*);

	sf::FloatRect getGlobalBounds() const;

	void draw(sf::RenderWindow&) const;

	void setLocation(sf::Vector2f);
	sf::Vector2f getLocation() const;

	void setColor(sf::Color);

	void setSize(sf::Vector2f);

	void updateTexture(sf::IntRect newRect);

private:

	sf::Sprite m_sprite;

};