#include "Toolbar.h"



Toolbar::Toolbar(toolbarObjects objs)
	:m_play(std::make_unique<Button>(sf::Vector2f(TB_OBJ_X, PLAY_Y), Type_t::play)),
	 m_arrowLButton(std::make_unique<Button>(sf::Vector2f(L_ARR_X, ARROWS_Y), Type_t::arrowLButton)),
	 m_arrowRButton(std::make_unique<Button>(sf::Vector2f(R_ARR_X, ARROWS_Y), Type_t::arrowRButton))
{
	for (auto& pair : objs)
		add(pair.first, pair.second);

	setBar();
}


bool Toolbar::clickedOnMe(sf::Vector2f loc) const
{
	if (m_play->getGlobalBounds().contains(loc) 
		|| m_arrowLButton->getGlobalBounds().contains(loc) 
		|| m_arrowRButton->getGlobalBounds().contains(loc)
		|| m_bar.getGlobalBounds().contains(loc))
	{
		return true;
	}
	return false;
}


Type_t Toolbar::handleClick(sf::Vector2f loc)
{
	Type_t type = none;

	if (m_play->mouseOnMe(loc) != none)
	{
		return play;
	}

	if (m_arrowLButton->mouseOnMe(loc) != none)
	{
		if(m_page!=0)
			m_page--;
		else
			m_page = m_toolbar.size()/(BUTTONS_IN_PAGE+1);
	}

	if (m_arrowRButton->mouseOnMe(loc) != none)
	{
		if(BUTTONS_IN_PAGE * (m_page + 1) < m_toolbar.size())
			m_page++;
		else
			m_page = 0;
	}

	for (auto i = BUTTONS_IN_PAGE*m_page; i < m_toolbar.size() && i < BUTTONS_IN_PAGE*(m_page+1); i++)
	{
		if (m_toolbar[i].mouseOnMe(loc) != none)
		{
			type = m_toolbar.at(i).getType();
			deleteObj(type);
			break;
		}
	}

	return type;

}

void Toolbar::addOrIncrease(Type_t objType, int amount)
{

	bool found = false;
	for (auto &button : m_toolbar)
	{
		if(button.getType() == objType)
		{
			button.increase();
			found = true;	
		}
	}
	if (!found)
		add(objType, amount);
	
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
			if(m_toolbar[i].isEmpty())
			{
				m_toolbar.erase(m_toolbar.begin() + i);
				updateLocs();
			}
			break;
		}
}


void Toolbar::draw(sf::RenderWindow& window) 
{	
	window.draw(m_bar);
	m_play->draw(window);
	m_arrowLButton->draw(window);
	m_arrowRButton->draw(window);

	
	for (auto i = (BUTTONS_IN_PAGE*m_page); i < m_toolbar.size() && i < BUTTONS_IN_PAGE*(m_page+1); i++)
	{
		m_toolbar[i].draw(window);
	}
}


void Toolbar::updateLocs()
{
	for (auto i = 0; i < m_toolbar.size(); i++)
	{
		m_toolbar[i].setPosition(sf::Vector2f(TB_OBJ_X, TB_TOP + SPACING + BUTTON_OBJ_SIZE/2 + (SPACING + BUTTON_OBJ_SIZE)*(i%BUTTONS_IN_PAGE)));
	}

}

void Toolbar::setBar()
{
	m_bar.setSize(sf::Vector2f(TB_W, TB_H));
	m_bar.setPosition(TB_X, TB_TOP);
	m_bar.setFillColor(sf::Color(32,239,238));
}


