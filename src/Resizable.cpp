#include "Resizable.h"


Resizable::Resizable(const sf::Vector2f& center, bool movable, b2World &world, Type_t type)
    :GameObj(center, false, movable, world, type)
{
    setTexture();
    setButtons();
}

void Resizable::setTexture()
{
    BaseImg::setIntRect(sf::IntRect(sf::Vector2i(FLOORING_MARGIN,FLOORING_MARGIN+(FLOORING_MARGIN*2+FLOORING_UNIT)*(m_whichSize-1)), sf::Vector2i(FLOORING_UNIT*(m_whichSize+2), FLOORING_UNIT)));
    BaseImg::setOrigin((FLOORING_UNIT*(m_whichSize+2))/2, FLOORING_UNIT/2);
    GameObj::updateBodySize();
}

void Resizable::makeItBigger()
{
    if(++m_whichSize == 6)//fix
        m_whichSize = 1;
    setTexture();
}

void Resizable::makeItSmaller()
{
    
    if(--m_whichSize == 0)
        m_whichSize = 5;//fix
    setTexture();

}

void Resizable::shiftL()
{
    m_whichAngle = (m_whichAngle+1)%3;
    rotateBody(m_whichAngle);
}
void Resizable::shiftR()
{
    m_whichAngle = (m_whichAngle-1)%3;
    rotateBody(m_whichAngle);
}


void Resizable::setButtons()
{
    auto center = BaseImg::getLocation();
    auto diff = BaseImg::getSize().x/2;
    m_buttons.push_back(Button(sf::Vector2f(center.x+diff, center.y+FLOORING_UNIT), Type_t::rotateButton));//fix
    m_buttons.push_back(Button(sf::Vector2f(center.x-diff, center.y+FLOORING_UNIT), Type_t::resizeButton));//fix
}


bool Resizable::clickedOnMe(sf::Vector2f loc)
{
    bool buttonClick = false;;
    for (auto &button : m_buttons)
        if(button.clickedOnMe(loc))
        {
            if (button.getType() == Type_t::resizeButton)
                makeItBigger();
            else if (button.getType() == Type_t::rotateButton)
                shiftL();//fix 
            
            buttonClick = true;
        }
    if(!buttonClick)
        return (Button::clickedOnMe(loc));

    return false;

}

void Resizable::draw(sf::RenderWindow& win) const
{
    BaseImg::draw(win);

    for (auto &button : m_buttons)
        button.draw(win);
}