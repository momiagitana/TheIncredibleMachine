#pragma once
#include "Button.h"


class ClickButton : public Button
{
private:
    bool m_mouseOnMe = false;

public:
    ClickButton(const sf::Vector2f& center, Type_t obj, sf::Vector2i intRectSize);
    ~ClickButton();

    bool mouseOnMe(sf::Vector2f loc);//fix override
};

