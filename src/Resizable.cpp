#include "Resizable.h"


Resizable::Resizable(const sf::Vector2f& center, bool movable, b2World &world, Type_t type)
    :GameObj(center, false, movable, world, type)
{
    setTexture();
}

void Resizable::setTexture()
{
    BaseImg::setIntRect(sf::IntRect(sf::Vector2i(FLOORING_MARGIN,FLOORING_MARGIN+(FLOORING_MARGIN*2+FLOORING_UNIT)*(m_whichSize-1)), sf::Vector2i(FLOORING_UNIT*(m_whichSize+2), FLOORING_UNIT)));
    GameObj::updateBodySize();
}

void Resizable::makeItBigger()
{
    if(++m_whichSize == 6)
        m_whichSize = 1;
    setTexture();
}

void Resizable::makeItSmaller()
{
    
    if(--m_whichSize == 0)
        m_whichSize = 5;
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

ObjInfo Resizable::getInfo()
{
    ObjInfo info = GameObj::getInfo();
    info.size = getWhichSize();
    return info;
}
