#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "Button.h"
using std::ostringstream;

class ToolbarButton : public Button
{
public:

	ToolbarButton(sf::Vector2f,Type_t,int);
	void increase();
	void decrease();
	bool isEmpty() const;
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow&) const;
	
private:
	void setString();

	int m_amount;

	sf::Text m_text;
};
