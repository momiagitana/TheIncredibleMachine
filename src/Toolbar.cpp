#include "Toolbar.h"

Toolbar::Toolbar(toolbarObjects objs)
	:m_indxPosAdjust(1),
	m_play(std::make_unique<Button>(sf::Vector2f(WINDOW_WIDTH-50,25), GameObject_t::play)),
	m_arrows(std::make_unique<Button>(sf::Vector2f(WINDOW_WIDTH-50,50 + 25), GameObject_t::arrows))
{
	for (auto& pair : objs)
		add(pair.first, pair.second);

	setbar();
	setPlayButton();
	setArrowsButton();
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


GameObject_t Toolbar::handleClick(sf::Vector2f loc)
{
	GameObject_t type = none;
	if (m_play->getGlobalBounds().contains(loc))
	{
		type = play;
	}

	for (auto& button : m_toolbar)
	{
		if (button.clicked(loc))
		{	
			type = button.getObj();
			deleteObj(type);
		}
	}

	return type;
}

void Toolbar::add(GameObject_t obj, int amount)
{
	bool found = false;
	for (auto &each : m_toolbar)
	{
		if(each.getObj() == obj)
		{
			each.increase();
			found = true;
		}
	}
	if (!found)
		m_toolbar.push_back(ToolbarButton(obj, amount));
	
}

void Toolbar::deleteObj(const GameObject_t& obj)
{
	for (auto i = 0; i < m_toolbar.size(); i++)
	{
		if (m_toolbar[i].getObj() == obj)
		{
			m_toolbar[i].decrease();
			if(!m_toolbar[i].getAmount())
			{
				m_toolbar.erase(m_toolbar.begin() + i);
			}
		}
	}
}

void Toolbar::draw(sf::RenderWindow& window) 
{	
	window.draw(m_bar);
	m_play->draw(window);
	m_arrows->draw(window);
	
	for (auto i = 0; i < m_toolbar.size(); i++)
	{
		m_toolbar[i].setPosition(sf::Vector2f(WINDOW_WIDTH - 50, 150 + i * 80));
		m_toolbar[i].draw(window);
	}

}

void Toolbar::setbar()
{
	m_bar.setSize(sf::Vector2f(100, 400));
	m_bar.setPosition(WINDOW_WIDTH - 100, 100);
	m_bar.setFillColor(sf::Color(sf::Color::White));
	m_bar.setOutlineColor(sf::Color::Yellow);
	m_bar.setOutlineThickness(-2);
}

void Toolbar::setPlayButton()
{
	m_play->setPosition(sf::Vector2f(WINDOW_WIDTH-50,25));
	m_play->setSize(sf::Vector2u(100,50));
}

void Toolbar::setArrowsButton()
{
	m_arrows->setPosition(sf::Vector2f(WINDOW_WIDTH-50,50 + 25));
	m_arrows->setSize(sf::Vector2u(100,50));
}

