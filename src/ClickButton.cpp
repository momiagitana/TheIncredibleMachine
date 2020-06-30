#include "ClickButton.h"

ClickButton::ClickButton(const sf::Vector2f& center,Type_t obj, sf::Vector2i intRectSize)
    :Button(center, obj)
{
    BaseImg::setIntRect(sf::IntRect(0, 0, intRectSize.x, intRectSize.y));
}

ClickButton::~ClickButton()
{
}

bool ClickButton::mouseOnMe(sf::Vector2f loc)
{
    if(Button::mouseOnMe(loc))
    {
        nextIntRect();
        return true;
    }

    prevIntRect();
    return false;    
}
