#include "Toolbar.h"

Toolbar::Toolbar(toolbarObjects v)
 :m_DATA(v),m_Idxloc(0),m_rec()
{
    for (auto i : m_DATA)
    {
        setButton(i);
    }
}

void Toolbar::setButton(toolbarPair p)
{
    m_toolbar.emplace_back(std::make_shared<Button>(p.first,p.second))
        ->setposition(sf::Vector2f(m_rec.getSize().x/m_DATA.size(),m_Idxloc*obj_size));
    setIdxLoc();
}

void Toolbar::draw(sf::RenderWindow& window)
{
    for (auto& i : m_toolbar)
    {
        i->draw(window);
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
        if (i->getGlobalBounds().contains(loc))
        {
            return true;
        }
    }
    return false;
}

ResourceManager::ToolBarobj_t Toolbar::toolbarClick(sf::Vector2f loc)
{
    for (auto& i : m_toolbar)
    {
        if (i->getGlobalBounds().contains(loc))
        {
            return i->clickedOnMe(loc);
        }
    }

    return ResourceManager::ToolBarobj_t::invalid;
}

void Toolbar::setDefalutToolbar()
{
    m_toolbar.emplace_back(std::make_shared<Button>(ResourceManager::ToolBarobj_t::Worker, 0))
        ->setposition(sf::Vector2f(0,0));
    setIdxLoc();

    m_toolbar.emplace_back(std::make_shared<Button>(ResourceManager::ToolBarobj_t::Arrows, 0))
        ->setposition(sf::Vector2f(0, 0));
    setIdxLoc();


    m_rec.setSize(sf::Vector2f(100, 300));
    m_rec.setPosition(500, 100);
    m_rec.setFillColor(sf::Color(sf::Color::White));
    m_rec.setOutlineColor(sf::Color::Yellow);
    m_rec.setOutlineThickness(-2);

}
