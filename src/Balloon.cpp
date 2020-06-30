#include "Balloon.h"


Balloon::Balloon(ObjInfo info, bool movable, b2World &world)
    :GameObj(info._loc, true, movable, world, balloon)
{
    setGravityScale(-0.3);
    setIntRect(sf::IntRect(0,0,INITIAL_SIZES[balloon][0],INITIAL_SIZES[balloon][1]));//fix
    updateBodySize();
}

bool Balloon::m_registerit = ObjFactory::registerit(balloon, [](ObjInfo info, bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Balloon>(info,movable,world); });


void Balloon::draw(sf::RenderWindow& window)
{
    if(endOfAnimation())
    {
        setGravityScale(0.01);
        setBodySize(sf::Vector2f(10,10));//fix
    }
	else if(isOn())
		animation();

	BaseImg::draw(window);
		
}

void Balloon::animation()
{
	if(getClock().getElapsedTime().asSeconds() > 0.04)
	{
		BaseImg::nextIntRect(ANIMATION_SIZES[0][0] ,ANIMATION_SIZES[0][1]);
		getClock().restart();	
	}	
	 
}