#include "Toolbar.h"
#include <iostream>
using std::cout;


Toolbar::Toolbar(std::vector<std::pair<GameObject_t, int>> v)
    :m_DATA(v), m_Idxloc(2), m_rec()
{
    setDefalutToolbar();
    for (auto i : m_DATA)
    {
        setButton(i);
    }
}

void Toolbar::setButton(std::pair<GameObject_t, int> p)
{
    m_toolbar.insert(std::pair<GameObject_t, std::shared_ptr<Button>>(p.first, std::make_shared<Button>(p.first, p.second)));
    m_toolbar.at(p.first)->setposition(sf::Vector2f(WINDOW_WIDTH - 50, m_Idxloc * 60));
    m_toolbar.at(p.first)->setTextpos(sf::Vector2f(WINDOW_WIDTH - 50, m_Idxloc * 60 + 20));
    m_toolbar.at(p.first)->setTextColor(sf::Color::Blue);
    m_toolbar.at(p.first)->setString();
    setIdxLoc();
}


void Toolbar::draw(sf::RenderWindow& window)
{
    window.draw(m_rec);

    for (auto& i : m_toolbar)
    {
        i.second->draw(window);
    }
}

void Toolbar::setIdxLoc()
{
    m_Idxloc++;
    if (m_Idxloc == 5)
    {
        m_Idxloc = 0;
    }
}

bool Toolbar::clickedOnMe(sf::Vector2f loc)
{

    for (auto& i : m_toolbar)
    {
        if (i.second->getGlobalBounds().contains(loc))
        {
            return true;
        }
    }
    return false;
}

GameObject_t Toolbar::toolbarClick(sf::Vector2f loc)
{
    for (auto i : m_toolbar)
    {
        if (i.second->getGlobalBounds().contains(loc))
        {
            if (!i.second->getlightStatus())
            {
                i.second->Decrease();
                if (i.second->getNumOfappear() == 0)
                {
                    m_toolbar.erase(i.first);
                }
                i.second->setString();
                i.second->light();
                return i.first;
            }
            else
            {
                i.second->Increase();
                i.second->setString();
                i.second->unlight();
                return i.first;
            }
        }
    }
}

void Toolbar::holdThisObj(GameObject_t obj)
{
    m_Current_at_hold = obj;
}

GameObject_t Toolbar::getCurrent_at_Hold()
{
    return m_Current_at_hold;
}

void Toolbar::take(GameObject_t obj)
{
    auto it = m_toolbar.find(obj);
    if (it != m_toolbar.end())
    {
        it->second->light();
        it->second->Decrease();
        it->second->setString();

    }
}

void Toolbar::drope(GameObject_t obj)
{
    auto it = m_toolbar.find(obj);
    if (it != m_toolbar.end())
    {
        it->second->unlight();
    }
}


void Toolbar::putback(GameObject_t obj)
{
    auto it = m_toolbar.find(obj);
    if (it != m_toolbar.end())
    {
        it->second->unlight();
        it->second->Increase();
    }
}



void Toolbar::UnlightOne(sf::Vector2f loc)
{
    for (auto& i : m_toolbar)
    {
        if (i.second->getGlobalBounds().contains(loc))
            i.second->unlight();
    }
}

void Toolbar::add(GameObject_t obj, int num_of_apear)
{
    auto it = m_toolbar.find(obj);
    if (it == m_toolbar.end())
    {
        setButton(std::pair<GameObject_t, int>(obj, num_of_apear));
        m_toolbar.at(obj)->unlight();
    }
    else
    {
        m_toolbar.at(obj)->Increase();
    }
}

void Toolbar::lightAll()
{
    for (auto& i : m_toolbar)
    {
        i.second->light();
    }
}

void Toolbar::UnlightAll()
{
    for (auto& i : m_toolbar)
    {
        i.second->unlight();
    }
}

void Toolbar::lightOne(sf::Vector2f objClicked)
{
    for (auto& i : m_toolbar)
    {
        if (i.second->getGlobalBounds().contains(objClicked))
            i.second->light();
    }
}

void Toolbar::setDefalutToolbar()
{
    setplayButton();
    setplayArrowsButton();
    setToolBaord();
}

void Toolbar::setplayButton()
{
    m_toolbar.insert(std::pair<GameObject_t, std::shared_ptr<Button>>
        (GameObject_t::play, std::make_shared<Button>(GameObject_t::play, 0)));
    m_toolbar.at(GameObject_t::play)->setposition(sf::Vector2f(WINDOW_WIDTH - 50, 0 + 25));
    m_toolbar.at(GameObject_t::play)->setSize(sf::Vector2u(100, 50));
}

void Toolbar::setplayArrowsButton()
{
    m_toolbar.insert(std::pair<GameObject_t, std::shared_ptr<Button>>
        (GameObject_t::arrows, std::make_shared<Button>(GameObject_t::arrows, 0)));
    m_toolbar.at(GameObject_t::arrows)->setposition(sf::Vector2f(WINDOW_WIDTH - 50, 50 + 25));
    m_toolbar.at(GameObject_t::arrows)->setSize(sf::Vector2u(100, 50));
}

void Toolbar::setToolBaord()
{
    m_rec.setSize(sf::Vector2f(100, 400));
    m_rec.setPosition(WINDOW_WIDTH - 100, 100);
    m_rec.setFillColor(sf::Color(sf::Color::Yellow));
    m_rec.setOutlineColor(sf::Color::Red);
    m_rec.setOutlineThickness(-4);
}


GameObject_t Toolbar::handleClick(sf::Vector2f loc)
{
    for(auto &obj : m_toolbar)
        if (obj.second->clicked(loc))
            if(obj.first <= play)
                return obj.first;
    
    return none;

}