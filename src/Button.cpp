#include "Button.h"
#include "Globals.h"
#include "ResourceManager.h"


Button::Button(const sf::Vector2f& center, Type_t obj)
	:BaseImg(center, obj),
	m_light(false) , 
	m_type(obj)
{
}

bool Button::clickedOnMe(sf::Vector2f loc)
{
	if (getGlobalBounds().contains(loc))
		return true;

	return false;
}

Type_t Button::getType()
{
	return Type_t(m_type%100);//fix global 
}

void Button::light()
{
	m_light = true;
}

void Button::unlight()
{
	m_light = false;
}


bool Button::getlightStatus()
{
	return m_light;
}

void Button::draw(sf::RenderWindow& w) const
{
	BaseImg::draw(w);
	
}