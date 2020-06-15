#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Resizable : public GameObj
{
public:
	Resizable(const sf::Vector2f& center, const sf::Vector2f& size, sf::Texture* texture, int which, bool movable, b2World &world);
	
    int getSize() const { return m_which; }
    void setSize(int size) { m_which = size; }

private:
	int m_which; //from 1 to 5

};

