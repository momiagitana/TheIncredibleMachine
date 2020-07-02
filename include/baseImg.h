#pragma once

#include <globals.h>
#include "ResourceManager.h"

class BaseImg
{
public:

	BaseImg(const sf::Vector2f, const Type_t);
	virtual ~BaseImg(){}
	virtual sf::FloatRect getGlobalBounds() const;
	virtual void draw(sf::RenderWindow&);

	sf::Vector2f getLocation() const;
	void setRotation(const float);
	void setColor(const sf::Color);
	void setSize(const sf::Vector2u);
	void setPosition(const sf::Vector2f);
	sf::Vector2f getSize() const;
	void setIntRect(const sf::IntRect);
	void setOrigin(const float, const float);
	void setScale(const float);
	virtual void drawSmall(sf::RenderTexture&);

	const sf::Sprite& getSprite() const { return m_sprite; }
	void nextIntRect(const int x = 0, const int y = 0);
	void prevIntRect();

	//fix check if used
	void setTextureRect(const sf::IntRect);
	const sf::IntRect& getTextureRect() const;

	bool endOfAnimation() { return m_endAnimation; } 
	void setEndAnimation(const bool status) { m_endAnimation = status; }

private:

	sf::Sprite m_sprite;

	bool m_endAnimation = false;
};