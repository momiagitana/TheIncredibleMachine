#include "Conveyor.h"

Conveyor::Conveyor (ObjInfo info, bool movable, b2World &world)
    :Connectable(info, movable, world, 1)
{
    setIntRect(sf::IntRect(0,0,INITIAL_SIZES[1][0],INITIAL_SIZES[1][1]));//fix
    updateBodySize();
}

bool Conveyor::m_registerit = ObjFactory::registerit(conveyor, [](ObjInfo info, bool movable, b2World &world)->std::shared_ptr<GameObj> { return std::make_shared<Conveyor>(info,movable,world); });

// void Conveyor::draw(sf::RenderWindow& window)
// {
//     if(endOfAnimation())
//     {
//         auto size = BaseImg::getSize();
//         BaseImg::setIntRect(sf::IntRect(0,0,size.x,size.y));//fix
//         setEndAnimation(false);
//     }
//     if(isOn())
// 	    animation();

// 	BaseImg::draw(window);
		
// }