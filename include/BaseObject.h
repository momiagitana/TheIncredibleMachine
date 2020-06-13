#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"




class BaseObject
{
public:

	BaseObject(const sf::Texture*, sf::Vector2f, sf::Vector2f);
	virtual ~BaseObject();
	sf::FloatRect getGlobalBounds()const;
	virtual void draw(sf::RenderWindow&);
	void setIntRect(sf::IntRect);
	void fixSize();
	bool checkCollision(const sf::FloatRect& floatRect) const;
	/*virtual void collide(BaseObject& baseObject) = 0;
	virtual void collide(Digger& digger) = 0;
	virtual void collide(Wall& wall) = 0;
	virtual void collide(Monster& monster) = 0;
	virtual void collide(Stone& stone) = 0;
	virtual void collide(Diamond& diamond) = 0;
	virtual void collide(ExtraStons& extrastons) = 0;
	virtual void collide(ExtraTime& extratime) = 0;
	virtual void collide(ExtraScore& extrascore) = 0;*/

protected:

	sf::Sprite m_sprite;
	sf::Vector2f m_size;
};
