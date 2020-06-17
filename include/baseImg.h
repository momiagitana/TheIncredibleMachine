#pragma once

#include <SFML/Graphics.hpp>
#include <globals.h>
#include "ResourceManager.h"

class BaseImg
{
public:

	BaseImg(sf::Vector2f, sf::Texture*);

	sf::FloatRect getGlobalBounds() const;

	void draw(sf::RenderWindow&) const;

	void setLocation(sf::Vector2f);
	sf::Vector2f getLocation() const;

	void setRotation(float);

	void setColor(sf::Color);

	void setSize(sf::Vector2u);
	virtual void setposition(sf::Vector2f loc);
	
	void updateTexture(sf::IntRect newRect);

	sf::Vector2f getSize() const;

	float PPM = 64.f;
    float MPP = 0.015625f;

private:

	sf::Sprite m_sprite;

};