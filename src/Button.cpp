#include "Button.h"
#include "Globals.h"

Button::Button(ResourceManager::ToolBarobj_t obj, int num_of_apperances)
	:BaseImg(sf::Vector2f(obj_size,obj_size),
		   sf::Vector2f(0,0),
		ResourceManager::instance().getToolBartexture(obj))
	,m_obj(obj),
	m_apperces_Counter(num_of_apperances)
{
}

ResourceManager::ToolBarobj_t Button::clickedOnMe(sf::Vector2f loc)
{
	return ResourceManager::ToolBarobj_t();
}
