#include "ToolbarButton.h"

ToolbarButton::ToolbarButton(sf::Vector2f center, Type_t objType, int numOfapp)
:m_amount(numOfapp),
Button(center, objType)
{
	//setSize(sf::Vector2u(BUTTON_OBJ_SIZE,BUTTON_OBJ_SIZE));
	m_text.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_text.setCharacterSize(15);
	m_text.setColor(sf::Color::Black);
	m_text.setString(std::to_string(m_amount));
}

void ToolbarButton::increase()
{
	m_amount++;
	m_text.setString(std::to_string(m_amount));
}

void ToolbarButton::decrease()
{
	m_amount--;
	m_text.setString(std::to_string(m_amount));
}

int ToolbarButton::getAmount()
{
	return m_amount;
}

void ToolbarButton::setPosition(sf::Vector2f pos)
{
	BaseImg::setPosition(pos);
	m_text.setPosition(sf::Vector2f(pos.x - 10, pos.y + getSize().y/2));//fix NUM_DIFF and -10 set origin center
}

void ToolbarButton::draw(sf::RenderWindow& w) const
{
	BaseImg::draw(w);
	w.draw(m_text);
}
