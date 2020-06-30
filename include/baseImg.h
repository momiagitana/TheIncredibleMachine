#pragma once

#include <SFML/Graphics.hpp>
#include <globals.h>
#include "ResourceManager.h"


class BaseImg
{
public:

	BaseImg(sf::Vector2f, Type_t);
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void draw(sf::RenderWindow&) const;

	sf::Vector2f getLocation() const;
	void setRotation(float);
	void setColor(sf::Color);
	void setSize(sf::Vector2u);
	void setPosition(sf::Vector2f loc);
	sf::Vector2f getSize() const;
	void setIntRect(sf::IntRect);
	void setOrigin(float, float);
	void setScale(float);
	virtual void drawSmall (sf::RenderTexture&);

	sf::Sprite getSprite() const { return m_sprite; } //fix ask if correct
	void nextIntRect(int x = 0, int y =0);
	void prevIntRect();
	bool endOfAnimation(){return m_endAnimation;}
	void setEndAnimation(bool status){m_endAnimation = status;}

private:

	sf::Sprite m_sprite;
	bool m_endAnimation = false;

};