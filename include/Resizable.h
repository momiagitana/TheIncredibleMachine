#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Button.h"
#include "globals.h"

class Resizable : public GameObj
{
public:
	Resizable(const sf::Vector2f& center,  bool movable, b2World &world, Type_t);
	
    int getWhichSize() const { return m_whichSize; }
    int getAngle() const { return m_whichAngle; }
    void setWhichSize(int size) { m_whichSize = size; }
    bool clickedOnMe(sf::Vector2f loc);
    void draw(sf::RenderWindow&) const;
    void setTexture();
    ObjInfo getInfo()const; //fix const

private:
	int m_whichSize = 1; //from 1 to 5
    int m_whichAngle = 0;
    std::vector<Button> m_buttons;

    void makeItBigger();
    void makeItSmaller();
    void shiftL();
    void shiftR();

    void setButtons();
};

