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
	int getAmount();
	void setString();
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow&) const;

private:

	int m_amount;

	sf::Text m_text;
};
