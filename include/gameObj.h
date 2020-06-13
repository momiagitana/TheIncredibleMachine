#pragma once

#include <SFML/Graphics.hpp>

#include <baseImg.h>
#include <PhyisicsObj.h>




class GameObj : public BaseImg
{
public:

	GameObj(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World &world);

	void draw (sf::RenderWindow&);
	//bool checkCollision(const sf::FloatRect& floatRect) const;


	// sf::Vector2f metToPix(b2Vec2 pos);
	// float metToPix(float met);

private:

	PhyisicsObj m_phyBody;
	//const float scaling = 100;
	
	void updateLoc();

	
};

