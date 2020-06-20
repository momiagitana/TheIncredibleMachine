#include "Toolbar.h"

Toolbar::Toolbar(toolbarObjects objs)
	:m_play(std::make_unique<Button>(sf::Vector2f(TB_OBJ_X,PLAY_Y), Type_t::play)),
	 m_arrows(std::make_unique<Button>(sf::Vector2f(TB_OBJ_X,ARROWS_Y), Type_t::arrows))
{
	for (auto& pair : objs)
		addOrIncrease(pair.first, pair.second);

	setBar();
		
	m_play->setSize(sf::Vector2u(TB_W, PLAY_BUTTON_H));
	m_arrows->setSize(sf::Vector2u(TB_W, ARROWS_BUTTON_H));
}

bool Toolbar::clickedOnMe(sf::Vector2f loc) const
{
	if (m_play->getGlobalBounds().contains(loc) 
		|| m_arrows->getGlobalBounds().contains(loc) 
		|| m_bar.getGlobalBounds().contains(loc))
	{
		return true;
	}
	return false;
}


Type_t Toolbar::handleClick(sf::Vector2f loc)
{
	Type_t type = none;
	if (m_play->getGlobalBounds().contains(loc))
	{
		type = play;
	}

	for (auto& button : m_toolbar)
	{
		if (button.clickedOnMe(loc))
		{	
			type = button.getType();
			deleteObj(type);
		}
	}
	return type;
}

void Toolbar::addOrIncrease(Type_t obj, int amount)
{
	bool found = false;
	for (auto &each : m_toolbar)
	{
		if(each.getType() == obj)
		{
			each.increase();
			found = true;
		}
	}
	if (!found)
		add(obj, amount);
	
}

void Toolbar::add(Type_t obj, int amount)
{
	m_toolbar.push_back(ToolbarButton(sf::Vector2f(0,0), Type_t(obj+100), amount));
	updateLocs();
}

void Toolbar::deleteObj(const Type_t& obj)
{
	for (auto i = 0; i < m_toolbar.size(); i++)
		if (m_toolbar[i].getType() == obj)
		{
			m_toolbar[i].decrease();
			if(!m_toolbar[i].getAmount())
			{
				m_toolbar.erase(m_toolbar.begin() + i);
				updateLocs();
			}
		}

}

void Toolbar::draw(sf::RenderWindow& window) 
{	
	window.draw(m_bar);
	m_play->draw(window);
	m_arrows->draw(window);
	
	for (auto i = 0; i < m_toolbar.size() && i < BUTTONS_IN_PAGE; i++)
		m_toolbar[i].draw(window);
}

void Toolbar::updateLocs()
{
	for (auto i = 0; i < m_toolbar.size(); i++)
		m_toolbar[i].setPosition(sf::Vector2f(TB_OBJ_X, TB_TOP + SPACING + BUTTON_OBJ_SIZE/2 + (SPACING + BUTTON_OBJ_SIZE)*(i%BUTTONS_IN_PAGE)));
}

void Toolbar::setBar()
{
	m_bar.setSize(sf::Vector2f(TB_W, TB_H));
	m_bar.setPosition(TB_X, TB_TOP);
	m_bar.setFillColor(sf::Color(sf::Color::White));
	m_bar.setOutlineColor(sf::Color::Yellow);
	m_bar.setOutlineThickness(-3);
}


