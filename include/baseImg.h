#pragma once

#include <SFML/Graphics.hpp>
#include <globals.h>
#include "ResourceManager.h"


class BaseImg
{
public:

	BaseImg(sf::Vector2f, Type_t);

	sf::FloatRect getGlobalBounds() const;

	virtual void draw(sf::RenderWindow&) const;

	//void setLocation(sf::Vector2f); fix

	sf::Vector2f getLocation() const;

	void setRotation(float);

	void setColor(sf::Color);

	void setSize(sf::Vector2u);
	
	void setPosition(sf::Vector2f loc);

	sf::Vector2f getSize() const;

	void setIntRect(sf::IntRect);

	void setOrigin(float, float);

	//float PPM = 64.f;
    //float MPP = 0.015625f; fix

private:

	sf::Sprite m_sprite;

};