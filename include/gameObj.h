#pragma once

#include <SFML/Graphics.hpp>

#include <baseImg.h>
#include <PhyisicsObj.h>




class GameObj : public BaseImg
{
public:

	GameObj(const sf::Vector2f& topLeft, const sf::Vector2f& size, sf::Texture* texture, bool dynamic, b2World* world);

	void draw (sf::RenderWindow&);
	//bool checkCollision(const sf::FloatRect& floatRect) const;


private:

	PhyisicsObj m_body;
	
	void updateLoc();

	
};

