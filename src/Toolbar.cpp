#include "Toolbar.h"
#include <iostream>
#include "BaseObject.h"
#include "Resources.h"

const int testSize = 16;


Toolbar::Toolbar(double x, double y)
{

	setDefalutToolbar(WINDOW_WIDTH,WINDOW_HEIGHT);
	setstrings();
}


void Toolbar::setButton(figure button, int numofapperienses, std::shared_ptr<BaseObject> obj)
{
	m_toolbarMap.insert(std::pair<figure, std::pair<int, std::shared_ptr<BaseObject>>>
		(button, std::pair<int, std::shared_ptr<BaseObject>>(numofapperienses, obj)));
}


figure Toolbar::toolbarclick(sf::Vector2f loc)
{

	for (auto it = m_toolbarMap.begin(); it != m_toolbarMap.end(); it++)
	{
		if (it->second.second->getGlobalBounds().contains(loc.x, loc.y))
		{
			return it->first;
		}
	}
	
	return figure::invalid;
}

void Toolbar::draw(sf::RenderWindow& window)
{
	window.draw(m_rec);
	window.draw(m_TextBar1);
	window.draw(m_TextBar2);
	window.draw(m_TextBar3);
	for (auto it = m_toolbarMap.begin(); it != m_toolbarMap.end(); it++)
	{
		it->second.second->draw(window);
	}
}

void Toolbar::setbuttonfillcolor(figure figure, sf::Color color)
{
	if (m_toolbarMap.find(figure) != m_toolbarMap.end())
	{
		m_toolbarMap.at(figure).second->setfillcolor(color);
	}
}

void Toolbar::setbuttonorigin(figure figure, sf::Vector2f origin)
{
	if (m_toolbarMap.find(figure) != m_toolbarMap.end())
	{
		m_toolbarMap.at(figure).second->setorigin(origin);
	}
}

void Toolbar::setbuttonIntRect(figure figure, sf::IntRect value)
{
	if (m_toolbarMap.find(figure) != m_toolbarMap.end())
	{
		m_toolbarMap.at(figure).second->setIntRect(value);
	}
}

void Toolbar::light(sf::Vector2f location)
{
	for (auto it = m_toolbarMap.begin(); it != m_toolbarMap.end(); it++)
	{
		if (it->second.second->getGlobalBounds().contains(location))
		{
			it->second.second->setfillcolor(sf::Color(255, 255, 255, 120));
			
		}
	}

}

void Toolbar::unlight(sf::Vector2f location)
{
	for (auto it = m_toolbarMap.begin(); it != m_toolbarMap.end(); it++)
	{
		if (it->second.second->getGlobalBounds().contains(location))
			it->second.second->setfillcolor(sf::Color(255,255,255,255));
	}
}


void Toolbar::setLevelObjects(figure first, int firstNumofapp,  
							  figure second,int secondNumofapp,	
							  figure third, int thirdNumofapp)
{
	m_firstObjCurrApp = firstNumofapp;
	m_secondObjCurrApp= secondNumofapp;
	m_thirdObjCurrApp = thirdNumofapp;

	setButton(first, firstNumofapp, std::make_shared<BaseObject>
		(Resources::instance().getRequestedTexture(first), sf::Vector2f(TOOLBAR_OBJ_X, FIRST_TOOLBAR_OBJ_Y), sf::Vector2f(obj_size, obj_size)));
	setbuttonorigin(first, sf::Vector2f(obj_size / 2, obj_size / 2));

	setButton(second, secondNumofapp, std::make_shared<BaseObject>
		(Resources::instance().getRequestedTexture(second), sf::Vector2f(TOOLBAR_OBJ_X, SECOND_TOOLBAR_OBJ_Y), sf::Vector2f(obj_size, obj_size)));
	setbuttonorigin(second, sf::Vector2f(obj_size / 2, obj_size / 2));

	setButton(third, secondNumofapp, std::make_shared<BaseObject>
		(Resources::instance().getRequestedTexture(third), sf::Vector2f(TOOLBAR_OBJ_X, THIRD_TOOLBAR_OBJ_Y), sf::Vector2f(obj_size, obj_size)));
	setbuttonorigin(third, sf::Vector2f(obj_size / 2, obj_size / 2));
}

void Toolbar::setStringbar()
{
	m_stringBar.str("");
	m_stringBar << m_firstObjCurrApp;
	m_TextBar1.setString(m_stringBar.str());
	m_stringBar.clear();
	m_stringBar.str("");
	m_stringBar << m_secondObjCurrApp;
	m_TextBar2.setString(m_stringBar.str());
	m_stringBar.clear();
	m_stringBar.str("");
	m_stringBar << m_thirdObjCurrApp;
	m_TextBar3.setString(m_stringBar.str());
}

void Toolbar::setDefalutToolbar(double x, double y)
{
	setButton(figure::Worker, 0, std::make_shared<BaseObject>
		(Resources::instance().getWorkerTexture(), sf::Vector2f(x - 100, 0), sf::Vector2f(100, 50)));

	setButton(figure::Arrows, 5, std::make_shared<BaseObject>
		(Resources::instance().getArrowsTexture(), sf::Vector2f(x - 100, y - 550), sf::Vector2f(100, 50)));

	m_rec.setSize(sf::Vector2f(100, 300));
	m_rec.setPosition(500, 100);
	m_rec.setFillColor(sf::Color(sf::Color::White));
	m_rec.setOutlineColor(sf::Color::Yellow);
	m_rec.setOutlineThickness(-2);
}

void Toolbar::setstrings()
{
	m_TextBar1.setStyle(sf::Text::Bold);
	m_TextBar1.setCharacterSize(testSize);
	m_TextBar1.setPosition(TOOLBAR_OBJ_X + obj_size / 2, FIRST_TOOLBAR_OBJ_Y + obj_size + 5);
	m_TextBar1.setFont(Resources::instance().getfont());
	m_TextBar1.setFillColor(sf::Color::Red);
	m_TextBar1.setString(m_stringBar.str());

	m_TextBar2.setStyle(sf::Text::Bold);
	m_TextBar2.setCharacterSize(testSize);
	m_TextBar2.setPosition(TOOLBAR_OBJ_X + obj_size / 2, SECOND_TOOLBAR_OBJ_Y + obj_size + 5);
	m_TextBar2.setFont(Resources::instance().getfont());
	m_TextBar2.setFillColor(sf::Color::Red);
	m_TextBar2.setString(m_stringBar.str());

	m_TextBar3.setStyle(sf::Text::Bold);
	m_TextBar3.setCharacterSize(testSize);
	m_TextBar3.setPosition(TOOLBAR_OBJ_X + obj_size / 2, THIRD_TOOLBAR_OBJ_Y + obj_size + 5);
	m_TextBar3.setFont(Resources::instance().getfont());
	m_TextBar3.setFillColor(sf::Color::Red);
	m_TextBar3.setString(m_stringBar.str());

}

void Toolbar::setLevelObjects(figure first, int firstNumofapp, figure second, int secondNumofapp)
{
	setButton(first, firstNumofapp, std::make_shared<BaseObject>
		(Resources::instance().getRequestedTexture(first), sf::Vector2f(TOOLBAR_OBJ_X, FIRST_TOOLBAR_OBJ_Y), sf::Vector2f(obj_size, obj_size)));
	setbuttonorigin(first, sf::Vector2f(obj_size / 2, obj_size / 2));

	setButton(second, secondNumofapp, std::make_shared<BaseObject>
		(Resources::instance().getRequestedTexture(second), sf::Vector2f(TOOLBAR_OBJ_X, SECOND_TOOLBAR_OBJ_Y), sf::Vector2f(obj_size, obj_size)));
	setbuttonorigin(second, sf::Vector2f(obj_size / 2, obj_size / 2));
}



