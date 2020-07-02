#pragma once
#include "GameObj.h"
#include "ResourceManager.h"
#include "Button.h"
#include "globals.h"


class Resizable : public GameObj
{
public:
	Resizable(const ObjInfo info, const bool, b2World &, const Type_t);
    virtual ~Resizable(){}
	
    int getWhichSize() const { return m_whichSize; }
    int getAngle() const { return m_whichAngle; }
    int getIfFliped() const { return m_isFliped; }

    void setWhichSize(const int size) { m_whichSize = size; }
   
    bool mouseOnMe(const sf::Vector2f )const;
    Type_t handleClick(const sf::Vector2f );
    void draw(sf::RenderWindow&);
    void setTexture();
    ObjInfo getInfo() const; //fix const
    void fixLastChange(const Type_t);
    void backToStartingPlace();
    void setPosition(const sf::Vector2f);

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

