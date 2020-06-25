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
    m_whichAngle = (m_whichAngle+1)%4;
    rotateBody(m_whichAngle);
}
void Resizable::shiftR()
{
    m_whichAngle = (m_whichAngle-1)%4;
    rotateBody(m_whichAngle);
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
    auto center = BaseImg::getLocation();
    auto diff = BaseImg::getSize().x/2;
    m_buttons.push_back(Button(sf::Vector2f(center.x+diff, center.y+FLOORING_UNIT), Type_t::rotateButton));//fix
    m_buttons.push_back(Button(sf::Vector2f(center.x-diff, center.y+FLOORING_UNIT), Type_t::resizeButton));//fix
}


bool Resizable::clickedOnMe(sf::Vector2f loc, Type_t&  whatHappen)
{
    if(GameObj::getMouseOverMe())//could be protected
    {
        for (auto &button : m_buttons)
            if(button.mouseOnMe(loc))
            {
                whatHappen = button.getType();
                if (whatHappen == Type_t::resizeButton)
                    makeItBigger();
                else if (whatHappen == Type_t::rotateButton)
                    shiftL();
                
                
                return false;
            }
    }

    return (Button::mouseOnMe(loc));
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
