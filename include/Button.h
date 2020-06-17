#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <sstream>
using std::ostringstream;

class Button : public BaseImg
{
public:

	Button(GameObject_t obj, int apearCounter);
	GameObject_t clicked(sf::Vector2f loc);
	virtual GameObject_t getobj();
	void light();
	void unlight();
	void Increase();
	void Decrease();
	int getNumOfappear();
	bool getlightStatus();
	void draw(sf::RenderWindow&) const;
	void setString();
	void setTextpos(sf::Vector2f pos);
	void clearString();
	void setTextColor(sf::Color color);

private:
	GameObject_t m_obj;
	int m_apearCounter;
	bool m_light;
	ostringstream m_srting;
	sf::Text m_text;
};