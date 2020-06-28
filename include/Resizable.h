#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Button.h"
#include "globals.h"


class Resizable : public GameObj
{
public:
	Resizable(ObjInfo info,  bool movable, b2World &world, Type_t);
	
    int getWhichSize() const { return m_whichSize; }
    int getAngle() const { return m_whichAngle; }
    int getIfFliped() const { return m_isFliped; }

    void setWhichSize(int size) { m_whichSize = size; }
   
    bool mouseOnMe(sf::Vector2f loc);
    Type_t handleClick(sf::Vector2f loc);
    void draw(sf::RenderWindow&) const;
    void setTexture();
    ObjInfo getInfo()const; //fix const
    void fixLastChange(Type_t);
    void backToStartingPlace();
    void setPosition(sf::Vector2f loc);

private:
	int m_whichSize = 1; //from 1 to 5
    int m_whichAngle = 0;
    int m_isFliped = -1;
    std::vector<Button> m_buttons;

    void makeItBigger();
    void makeItSmaller();
    void shiftL();
    void shiftR();

    void setButtons();
    void resetButtonsPos();
};

