#include "Resizable.h"


Resizable::Resizable(ObjInfo info, bool movable, b2World &world, Type_t type)
    :GameObj(info._loc, false, movable, world, type), m_whichAngle(info._angle), m_whichSize(info._size)
{
    setTexture();
    rotateBody(m_whichAngle);
    setButtons();
}

void Resizable::setPosition(sf::Vector2f loc)
{
    GameObj::setPosition(loc);
    resetButtonsPos();
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
    resetButtonsPos(); //fix move to setTexture
}

void Resizable::makeItSmaller()
{
    
    if(--m_whichSize == 0)
        m_whichSize = 5;//fix
    setTexture();
    resetButtonsPos();

}

void Resizable::shiftL()
{
    m_whichAngle = (m_whichAngle+1)%4;
    rotateBody(m_whichAngle);
    resetButtonsPos();
}
void Resizable::shiftR()
{
    m_whichAngle = (m_whichAngle-1)%4;
    rotateBody(m_whichAngle);
    resetButtonsPos();
}

ObjInfo Resizable::getInfo() const
{
    ObjInfo info = GameObj::getInfo();
    info._size = getWhichSize();
    info._angle = getAngle();
    info._fliped = getIfFliped();
    return info;
}


void Resizable::setButtons()
{
    m_buttons.push_back(Button(sf::Vector2f(0, 0), Type_t::rotateButton));//fix
    m_buttons.push_back(Button(sf::Vector2f(0, 0), Type_t::resizeButton));//fix
    resetButtonsPos();
}

void Resizable::resetButtonsPos()
{
    auto space = 0;
    auto globalBounds = BaseImg::getGlobalBounds();
    auto left = globalBounds.left;
    auto y = globalBounds.top + globalBounds.height + 4;//fix BUTTON_SIZE/2
    if (m_buttons.size() > 1)
        space = globalBounds.width/(m_buttons.size()-1);

    for (int i = 0; i < m_buttons.size(); i++)
        m_buttons[i].setPosition(sf::Vector2f(left + space * (i), y));
}


bool Resizable::clickedOnMe(sf::Vector2f loc, Type_t&  whatHappen) //fix delete if not using
{
    // if(GameObj::getMouseOverMe())//could be protected
    // {
    //     for (auto &button : m_buttons)
    //         if(button.mouseOnMe(loc))
    //         {
    //             whatHappen = button.getType();
    //             if (whatHappen == Type_t::resizeButton)
    //                 makeItBigger();
    //             else if (whatHappen == Type_t::rotateButton)
    //                 shiftL();
                
                
    //             return false;
    //         }
    // }

     return true;
}

Type_t Resizable::mouseOnMe(sf::Vector2f loc)
{
    Type_t clicked = none;
    if(GameObj::getMouseOverMe())//could be protected
    {
        for (auto &button : m_buttons)
        {
            clicked = button.mouseOnMe(loc);
            if(clicked == resizeButton)
            {
                makeItBigger();
                break;
            }

            else if (clicked == rotateButton)
            {
                shiftL();
                break;
            }
        }
    }

    if (clicked != none)
        return clicked;
    
    return GameObj::mouseOnMe(loc);

}

void Resizable::draw(sf::RenderWindow& win) const
{
    BaseImg::draw(win);

    if(GameObj::getMouseOverMe())
    {
        for (auto &button : m_buttons)
            button.draw(win);
    }
}

void Resizable::fixLastChange(Type_t change)
{
    if(change == Type_t::resizeButton)
        makeItSmaller();
    else
        shiftR();
    
}

void Resizable::backToStartingPlace()
{
    GameObj::backToStartingPlace();
    rotateBody(m_whichAngle);
}
