#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <globals.h>

class Animation
{
public:
    Animation(sf::Sprite& ,Type_t);

    void drawAnimation(sf::RenderWindow& window);

    void updateSprite();

    bool finishedAnim();

private:


    sf::Clock m_clock;

    bool m_animationFinished;
    
};

