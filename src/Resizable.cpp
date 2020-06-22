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
    
    rotateBody(-RAD_45);

}
void Resizable::shiftR()
{
    rotateBody(RAD_45);
}


void Resizable::setButtons()
{
    m_buttons.push_back(Button(BaseImg::getLocation(), Type_t::rotateButton));
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