#pragma once
#include "GameObj.h"
#include "ResourceManager.h"

class Resizable : public GameObj
{
public:
	Resizable(const sf::Vector2f& center,  bool movable, b2World &world, Type_t);
	
    int getWhichSize() const { return m_whichSize; }
    void setSize(int size) { m_whichSize = size; }

    void setTexture();
    void makeItBigger();
    void makeItSmaller();
    void shiftL();
    void shiftR();
    ObjInfo getInfo();

private:
	int m_whichSize = 1; //from 1 to 5

};

