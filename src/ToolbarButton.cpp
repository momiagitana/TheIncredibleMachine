#include "ToolbarButton.h"

ToolbarButton::ToolbarButton(GameObject_t obj, int numOfapp):m_apearCounter(numOfapp),Button(sf::Vector2f(obj_size, obj_size),obj)
{
	m_apearCounter += numOfapp;
	m_text.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_text.setCharacterSize(15);
	m_text.setPosition(0, 0);
	m_srting.str();
	m_srting << m_apearCounter;
	m_text.setColor(sf::Color::Black);
	m_text.setString(m_srting.str());
}

void ToolbarButton::Increase()
{
	m_apearCounter++;
}

void ToolbarButton::Decrease()
{
	m_apearCounter--;
}

int ToolbarButton::getNumOfappear()
{
	return m_apearCounter;
}

void ToolbarButton::setString()
{
	m_srting.str("");
	m_srting << m_apearCounter;
	m_text.setString(m_srting.str());
}

void ToolbarButton::setTextpos(sf::Vector2f pos)
{
	m_text.setPosition(pos);
}

void ToolbarButton::clearString()
{
	m_srting.clear();
}

void ToolbarButton::setTextColor(sf::Color color)
{
	m_text.setColor(color);
}

void ToolbarButton::draw(sf::RenderWindow& w) const
{
	w.draw(m_text);
}
