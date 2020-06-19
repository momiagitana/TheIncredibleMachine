#include "Toolbar.h"


//  --- constractor---

//  gets toolbarObjects davavector
//  Builds play button and arrows play 
//  Builds buttons out of toolbarObjects davavector

//each Button has counter wich is sf::text object

Toolbar::Toolbar(toolbarObjects davavector)
	:m_indxPosAdjust(1),
	m_play(std::make_unique<Button>(GameObject_t::play,0)),
	m_arrows(std::make_unique<Button>(GameObject_t::arrows,0))
{
	for (auto& pair : davavector)
	{
		m_toolbar.insert(std::make_pair(pair.first,std::make_unique<Button>(pair.first,pair.second)));
		m_toolbar.at(pair.first)->setposition(sf::Vector2f(WINDOW_WIDTH-50,100 + m_indxPosAdjust*80));
        m_toolbar.at(pair.first)->setTextpos(sf::Vector2f(WINDOW_WIDTH-50,100 +  m_indxPosAdjust*80+15));
        m_toolbar.at(pair.first)->setTextColor(sf::Color::Blue);
        m_toolbar.at(pair.first)->setString();
	    m_indxPosAdjust++;
	}
	setbar();
	setplayButton();
	setarrowsButton();
}


// clickedOnME
// will go threw all toolbar object
//includes:     m_play Button, m_arrows Button, and all boardButtons vector
// return true if mouse location hits any one of them
// if not     returns false


bool Toolbar::clickedOnMe(sf::Vector2f loc) const
{
	if (m_play->getGlobalBounds().contains(loc) 
		|| m_arrows->getGlobalBounds().contains(loc) 
		|| m_Bar.getGlobalBounds().contains(loc))
	{
		return true;
	}
	return false;
}


//handelclick

// return the object hits by mouse locations
// return Gamobject::none if not

GameObject_t Toolbar::handelclick(sf::Vector2f loc)
{
	if (m_play->getGlobalBounds().contains(loc))
	{
		return GameObject_t::play;
	}

	for (auto& button : m_toolbar)
	{
		if (button.second->getGlobalBounds().contains(loc))
		{	
			Delete(button.first);
		    return button.first;
		}
	}

	return GameObject_t::none;
}


//add

//if pair requested is not in map allreay  wil Constracts a new button with pair data
// if pair allready there will just increases counter by one

void Toolbar::add(GameObject_t obj, int amount)
{

	auto it = m_toolbar.find(obj);
	if (it == m_toolbar.end())
	{
		m_toolbar.insert(std::make_pair(obj,std::make_unique<Button>(obj, amount)));
		m_toolbar.at(obj)->setposition(sf::Vector2f(WINDOW_WIDTH - 50, 100 + m_indxPosAdjust*80));
		m_toolbar.at(obj)->setTextpos(sf::Vector2f(WINDOW_WIDTH - 50, 100 + m_indxPosAdjust*80+15));
		m_toolbar.at(obj)->setTextColor(sf::Color::Blue);
		m_toolbar.at(obj)->setString();
		m_indxPosAdjust++;
	}
	else
		m_toolbar.at(obj)->Increase();
}


// Delete
// will Deacrese object counter by one
// if obj counter == 0  will earase from vector
void Toolbar::Delete(const GameObject_t& obj)
{
	auto it = m_toolbar.find(obj);
	if (it != m_toolbar.end())
	{
		m_toolbar.at(obj)->Decrease();
		if (m_toolbar.at(obj)->getNumOfappear() == 0)
		{
			m_toolbar.erase(obj);
			m_indxPosAdjust--;

		}
	}
}


// draw all toolbar objects on requested window
//includes:   play button, arrows butoon, and all boardoOjects Buttons

void Toolbar::draw(sf::RenderWindow& window) 
{	
	locationAddjuste();
	window.draw(m_Bar);
	m_play->draw(window);
	m_arrows->draw(window);
	

	for (auto& button : m_toolbar)
	{
		button.second->setString();
		button.second->draw(window);
	}

}

void Toolbar::locationAddjuste()
{
	m_indxPosAdjust = 1;
	for (auto i = m_toolbar.begin(); i!=m_toolbar.end(); i++)
	{
		i->second->setposition(sf::Vector2f(WINDOW_WIDTH - 50, 100+m_indxPosAdjust * 80));
		i->second->setTextpos(sf::Vector2f(WINDOW_WIDTH - 50, 100 + m_indxPosAdjust * 80 + 15));
		i->second->setTextColor(sf::Color::Blue);
		i->second->setString();
		m_indxPosAdjust++;
	}
}


//seting the rectangle bar

void Toolbar::setbar()
{
	m_Bar.setSize(sf::Vector2f(100, 400));
	m_Bar.setPosition(WINDOW_WIDTH - 100, 100);
	m_Bar.setFillColor(sf::Color(sf::Color::White));
	m_Bar.setOutlineColor(sf::Color::Yellow);
	m_Bar.setOutlineThickness(-2);
}

//seting the play button
void Toolbar::setplayButton()
{
	m_play->setposition(sf::Vector2f(WINDOW_WIDTH-50,25));
	m_play->setSize(sf::Vector2u(100,50));
}

//seting the arrows button
void Toolbar::setarrowsButton()
{
	m_arrows->setposition(sf::Vector2f(WINDOW_WIDTH-50,50 + 25));
	m_arrows->setSize(sf::Vector2u(100,50));
}




