#include "Balloon.h"


Balloon::Balloon(ObjInfo info, bool movable, b2World &world)
    :GameObj(info._loc, true, movable, world, balloon)
{
    setGravityScale(-0.3);
    setIntRect(sf::IntRect(0,0,32,48));//fix
    updateBodySize();
}

bool Balloon::m_registerit = ObjFactory::registerit(balloon, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Balloon>(info,movable,world); });


void Balloon::draw(sf::RenderWindow& window)
{
    if(endOfAnimation())
    {
        setGravityScale(0.1);
        setBodySize(sf::Vector2f(10,10));//fix
    }
	else if(isOn())
		animation();

	BaseImg::draw(window);
		
}

void Balloon::animation()
{
	if(getClock().getElapsedTime().asSeconds() > 0.5)
	{
		BaseImg::nextIntRect(90,73);
		getClock().restart();	
	}	
	 
}

void Balloon::backToStartingPlace()
{
    setStatus(false);
    setGravityScale(-0.3);
    setIntRect(sf::IntRect(0,0,32,48));//fix
    updateBodySize();
    setEndAnimation(false);
    GameObj::backToStartingPlace();
}