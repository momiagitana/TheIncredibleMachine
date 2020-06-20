#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using std::ostringstream;

class Button : public BaseImg
{
public:

	Button(const sf::Vector2f& center,Type_t obj);
	bool clickedOnMe(sf::Vector2f loc);
	Type_t getType();
	void light();
	void unlight();
	bool getlightStatus();//?
	void draw(sf::RenderWindow&) const;

	
private:
	Type_t m_type;
	bool m_light;

};