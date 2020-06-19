#include "Button.h"
#include "Globals.h"
#include "ResourceManager.h"


Button::Button(GameObject_t obj, int apearCounter)
	:BaseImg(sf::Vector2f(obj_size, obj_size), ResourceManager::instance().getTexture(obj)), 
	m_light(false) , 
	m_obj(obj),
	m_apearCounter(0)
{

	m_apearCounter += apearCounter;
	m_text.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_text.setCharacterSize(15);
	m_text.setPosition(0, 0);
	m_srting.str();
	m_srting << m_apearCounter;
	m_text.setColor(sf::Color::Black);
	m_text.setString(m_srting.str());

}

GameObject_t Button::clicked(sf::Vector2f loc)
{
	if (getGlobalBounds().contains(loc))
	{
		return getobj();
	}
	return none;
}

GameObject_t Button::getobj()
{
	return m_obj;
}

void Button::light()
{
	m_light = true;
	setColor(sf::Color(255, 255, 255, 120));

}

void Button::unlight()
{
	m_light = false;
	setColor(sf::Color(255, 255, 255, 255));
}

void Button::Increase()
{
	m_apearCounter++;
}

void Button::Decrease()
{
	m_apearCounter--;
}

int Button::getNumOfappear()
{
	return m_apearCounter;
}

bool Button::getlightStatus()
{
	return m_light;
}


void Button::draw(sf::RenderWindow& w) const
{
	BaseImg::draw(w);
	w.draw(m_text);
}

void Button::setTextpos(sf::Vector2f pos)
{
	m_text.setPosition(pos);
}

void Button::setString()
{
	m_srting.str("");
	m_srting << m_apearCounter;
	m_text.setString(m_srting.str());
}

void Button::clearString()
{
	m_srting.clear();
}

void Button::setTextColor(sf::Color color)
{
	m_text.setColor(color);
}

