#include "Trampoline.h"

Trampoline::Trampoline(const ObjInfo info, const bool movable, b2World &world)
    :GameObj(info._loc, STATIC, movable, world, info._typ)
{
    setIntRect(sf::IntRect(0,0,48,31));//fix
    updateBodySize();
}

bool Trampoline::m_registerit = ObjFactory::registerit(trampoline, [](const ObjInfo info, const bool movable, b2World &world) -> std::shared_ptr<GameObj> { return std::make_shared<Trampoline>(info,movable,world);});


void Trampoline::draw(sf::RenderWindow& window)
{
    if(endOfAnimation())
    {
        auto size = BaseImg::getSize();
        BaseImg::setIntRect(sf::IntRect(0,0,size.x,size.y));//fix
        setEndAnimation(false);
        setStatus(false);
    }
	else if(isOn())
		animation();

	BaseImg::draw(window);
		
}

void Trampoline::animation()
{
	if(getClock().getElapsedTime().asSeconds() > 0.5)
	{
		BaseImg::nextIntRect(48,31);
		getClock().restart();	
	}	
	 
}