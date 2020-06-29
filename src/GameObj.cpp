#include "GameObj.h"

GameObj::GameObj(const sf::Vector2f& center, const bool dynamic, bool movable, b2World &world, Type_t type)
	:Button(center, type), m_phyObj(world, center, dynamic, type), m_movable(movable), m_initialLoc(center)
{
	static int ID = 0;
	m_ID = ID;
	ID ++;
	updateLoc();
	m_phyObj.setID(m_ID);
}

void GameObj::updateLoc()
{
	auto pos = m_phyObj.getPosition();
	BaseImg::setPosition(sf::Vector2f(pos.x * PPM, pos.y * PPM));
	BaseImg::setRotation(m_phyObj.getAngle());
}

void GameObj::backToStartingPlace()
{
	setPosition(m_initialLoc);
}

void GameObj::setInitialLoc()
{
	m_initialLoc = getLocation();
}

void GameObj::setPosition(sf::Vector2f loc)
{
	m_phyObj.setPosition(loc);
	updateLoc();
}

void GameObj::setGravityScale(float scale)
{
	m_phyObj.setGravityScale(scale);
}

void GameObj::updateBodySize()
{
	m_phyObj.setSize(BaseImg::getSize());
}

void GameObj::rotateBody(int whichAngle)
{
	m_phyObj.setAngle(whichAngle);
	BaseImg::setRotation(m_phyObj.getAngle());
}

ObjInfo GameObj::getInfo() const
{
	ObjInfo info;
	info._loc = getLocation();
	info._typ = getType();
	return info;
}

void GameObj::draw(sf::RenderWindow& window) const
{
	//  if(isOn() )
	//   	animate();
	// else
	// {
	// }
	
}

void GameObj::animate()
{
    // if(m_clock.restart().asSeconds() > 0.04)
	// 	BaseImg::nextIntRect();

    // if(m_currX > animationAmounts[m_type % 200]) //check this modulu shit!
    // {
    //   m_currX = 0;
    //   m_finished = true;
    // }

    // sf::IntRect newRect(m_currX * animationSizes[m_type % 200].x, 0,  animationSizes[m_type % 200].x, animationSizes[m_type % 200].y);

    // m_sprite.setTextureRect(newRect);

    // m_clock.restart();
}
