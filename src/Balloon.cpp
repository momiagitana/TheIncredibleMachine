#include "Balloon.h"


Balloon::Balloon(const ObjInfo info, const bool movable, b2World &world)
    :GameObj(info._loc, true, movable, world, balloon)
{
    setGravityScale(-0.3);
    setIntRect(sf::IntRect(0,0,32,48));//fix
    updateBodySize();
}

bool Balloon::m_registerit = ObjFactory::registerit(balloon, [](const ObjInfo info, const bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Balloon>(info,movable,world); });


void Balloon::draw(sf::RenderWindow& window)
{
    if(endOfAnimation())
    {
        setGravityScale(BALLOON_GRAVITY);
        setBodySize(sf::Vector2f(10,10));//fix
    }
	else if(isOn())
		animation();

	BaseImg::draw(window);
		
}

void Balloon::animation()
{
	if(getClock().getElapsedTime().asSeconds() > ANIMATION_TIME)
	{
		BaseImg::nextIntRect(BALLOON_WIDTH,BALLOON_HEIGHT);
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