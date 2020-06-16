#include "Toolbar.h"


Toolbar::Toolbar(std::vector<std::pair<GameObject_t,int>> v)
 :m_DATA(v),m_Idxloc(0),m_rec()
{
    setDefalutToolbar();
    for (auto i : m_DATA)
    {
        setButton(i);
    }
}

void Toolbar::setButton(std::pair<GameObject_t, int> p)
{
    m_toolbar.emplace_back(std::make_shared<Button>(p.first, p.second))
        ->setposition(sf::Vector2f(WINDOW_WIDTH-50, 0+100+m_Idxloc*80));
    setIdxLoc();
}


void Toolbar::draw(sf::RenderWindow& window)
{
    window.draw(m_rec);
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

GameObject_t Toolbar::toolbarClick(sf::Vector2f loc)
{
    for (auto i : m_toolbar)
    {
        if (i->getGlobalBounds().contains(loc))
        {
            return i->getobj();
        }
    }
}

void Toolbar::setDefalutToolbar()
{
    m_toolbar.emplace_back(std::make_shared<Button>(GameObject_t::worker, 0))
        ->setposition(sf::Vector2f(WINDOW_WIDTH, 0));
    m_toolbar.at(0)->setSize(sf::Vector2f(100, 50));
    setIdxLoc();

    m_toolbar.emplace_back(std::make_shared<Button>(GameObject_t::arrows, 0))
        ->setposition(sf::Vector2f(WINDOW_WIDTH,50));
    m_toolbar.at(1)->setSize(sf::Vector2f(100, 50));
    setIdxLoc();
    

    m_rec.setSize(sf::Vector2f(100, 400));
    m_rec.setPosition(WINDOW_WIDTH-100, 100);
    m_rec.setFillColor(sf::Color(sf::Color::White));
    m_rec.setOutlineColor(sf::Color::Yellow);
    m_rec.setOutlineThickness(-2);

}
