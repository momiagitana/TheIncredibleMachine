#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Button.h"
using std::ostringstream;
class ToolbarButton : public Button
{
public:
	ToolbarButton(GameObject_t obj,int);
	void Increase();
	void Decrease();
	int getNumOfappear();
	void setString();
	void setTextpos(sf::Vector2f pos);
	void clearString();
	void setTextColor(sf::Color color);
	void draw(sf::RenderWindow&) const;
private:
	int m_apearCounter;
	ostringstream m_srting;
	sf::Text m_text;
};
