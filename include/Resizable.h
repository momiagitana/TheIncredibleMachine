#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Resizable : public GameObj
{
public:
	Resizable(const sf::Vector2f& center, const sf::Vector2u& size, sf::Texture* texture, bool movable, b2World &world, GameObject_t);
	
    int getSize() const { return m_which; }
    void setSize(int size) { m_which = size; }

    void setTexture();
    void makeItBigger();
    void makeItSmaller();
    void shiftL();
    void shiftR();

private:
	int m_which = 2; //from 1 to 5

};

