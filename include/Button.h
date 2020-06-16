#pragma once

#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

class Button : public BaseImg
{
public:
	Button(ResourceManager::ToolBarobj_t obj, int num_of_apperances);
	ResourceManager::ToolBarobj_t clickedOnMe(sf::Vector2f loc);

private:
	ResourceManager::ToolBarobj_t m_obj;
	int m_apperces_Counter;
};