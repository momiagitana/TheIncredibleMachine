#include "Button.h"
#include "Globals.h"


Button::Button(GameObject_t obj, int apearCounter)
	:BaseImg(sf::Vector2f(obj_size,obj_size),sf::Vector2f(0,0),ResourceManager::instance().getTexture(obj)),
	m_obj(obj),
	m_apearCounter(apearCounter)
{
}

GameObject_t Button::clicked(sf::Vector2f loc)
{
	return GameObject_t();
}

int Button::getNumOfApeariences()
{
	return m_apearCounter;
}

void Button::DecreaseNumOfApeariences()
{
	m_apearCounter--;
}

void Button::IncreaseNumOfApeariences()
{
	m_apearCounter++;
}
