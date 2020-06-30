#include "ClickButton.h"

ClickButton::ClickButton(const sf::Vector2f& center,Type_t obj)
    :Button(center, obj)
{
}

ClickButton::~ClickButton()
{
}


bool mouseOnMe(sf::Vector2f loc)
{
   return true;//Button::mouseOnMe(loc);
}