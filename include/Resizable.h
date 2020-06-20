#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Resizable : public GameObj
{
public:
	Resizable(const sf::Vector2f& center,  bool movable, b2World &world, Type_t);
	
    int getSize() const { return m_which; }
    void setSize(int size) { m_which = size; }

    void setTexture();
    void makeItBigger();
    void makeItSmaller();
    void shiftL();
    void shiftR();

private:
	int m_which = 1; //from 1 to 5

};

