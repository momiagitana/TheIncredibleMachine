#include "ToolbarButton.h"

ToolbarButton::ToolbarButton(GameObject_t obj, int numOfapp)
:m_amount(numOfapp),Button(sf::Vector2f(obj_size, obj_size),obj)
{
	m_text.setFont(ResourceManager::instance().getFont(ResourceManager::Font::kongtext));
	m_text.setCharacterSize(15);
	m_text.setColor(sf::Color::Black);

}

void ToolbarButton::increase()
{
	m_amount++;
}

void ToolbarButton::decrease()
{
	m_amount--;
}

int ToolbarButton::getAmount()
{
	return m_amount;
}

void ToolbarButton::setPosition(sf::Vector2f pos)
{
	BaseImg::setPosition(pos);
	m_text.setString(std::to_string(m_amount));
	m_text.setPosition(sf::Vector2f(pos.x, pos.y + 20));//fix NUM_DIFF
}

void ToolbarButton::draw(sf::RenderWindow& w) const
{
	BaseImg::draw(w);
	w.draw(m_text);
}
