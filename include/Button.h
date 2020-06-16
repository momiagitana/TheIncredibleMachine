#pragma once

#pragma once
#include "baseImg.h"
#include "ResourceManager.h"
#include <SFML/Graphics.hpp>

class Button : public BaseImg
{
public:
	Button(GameObject_t obj, int apearCounter);
	GameObject_t clicked(sf::Vector2f loc);
	int getNumOfApeariences();
	void DecreaseNumOfApeariences();
	void IncreaseNumOfApeariences();
	virtual GameObject_t getobj();

private:
	GameObject_t m_obj;
	int m_apearCounter;
};