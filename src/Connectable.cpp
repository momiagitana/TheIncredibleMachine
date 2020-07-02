#include "Connectable.h"


Connectable::Connectable(const ObjInfo info, const bool movable, b2World &world, const int typeOfEngine)//fix pass int on ObjInfo
    :GameObj(info._loc, STATIC, movable, world, info._typ),
    m_connection((sf::Vector2f(info._loc.x, info._loc.y)), connectButton)
{
    m_buttonDelta = sf::Vector2f(DELTA_ENGINE_CONECT[typeOfEngine][0],DELTA_ENGINE_CONECT[typeOfEngine][1]);
    setPosition(info._loc);
}

Connectable::~Connectable()
{
}

void Connectable::setPosition(const sf::Vector2f loc)
{
    GameObj::setPosition(loc);
    m_connection.setPosition(sf::Vector2f(loc.x + m_buttonDelta.x, loc.y + m_buttonDelta.y));
}


Type_t Connectable::handleClick(const sf::Vector2f loc)
{
    if(m_connection.mouseOnMe(loc))
        return m_connection.getType();

    return getType();
}


void Connectable::backToStartingPlace()
{
    GameObj::backToStartingPlace();
    setStatus(false);//fix OFF
}

void Connectable::draw(sf::RenderWindow& window)
{
    if(endOfAnimation())
    {
        auto size = BaseImg::getSize();
        BaseImg::setIntRect(sf::IntRect(0,0,size.x,size.y));//fix
        setEndAnimation(false);
    }
    else if(isOn())
	    animation();

	BaseImg::draw(window);		
}

void Connectable::animation()
{
    auto size = BaseImg::getSize();

	if(getClock().getElapsedTime().asSeconds() > 0.4)
	{
		BaseImg::nextIntRect(size.x ,size.y);
		getClock().restart();	
	}
	 
}