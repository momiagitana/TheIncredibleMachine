#pragma once
#include "Button.h"


class ClickButton : public Button
{

public:
    ClickButton(const sf::Vector2f& center,Type_t obj);
    ~ClickButton();

    bool mouseOnMe(sf::Vector2f loc);
};

