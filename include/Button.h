#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using std::ostringstream;

class Button : public BaseImg
{
public:

	Button(const sf::Vector2f& center,GameObject_t obj);
	GameObject_t clicked(sf::Vector2f loc);
	virtual GameObject_t getobj();
	void light();
	void unlight();
	bool getlightStatus();//?
	void draw(sf::RenderWindow&) const;
	

private:
	GameObject_t m_obj;
	
	bool m_light;
	
	
};