#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>


float scaling = 100;

sf::Vector2f metersToPixels(float xMeters, float yMeters)
{
    return  sf::Vector2f(metToPix(xMeters), metToPix(yMeters));    
}
sf::Vector2f metersToPixels(b2Vec2 meters)
{
    return  sf::Vector2f(metToPix(meters.x), metToPix(meters.y));
}

float pixToMet(float pix)
{
    return pix * scaling;
}

float metToPix(float met)
{
    return met / scaling;
}

b2Vec2 pixelsToMeters(float xPixels, float yPixels)
{
    return  b2Vec2(pixToMet(xPixels), pixToMet(yPixels));    
}
b2Vec2 pixelsToMeters(sf::Vector2f pixels)
{
    return  b2Vec2(pixToMet(pixels.x), pixToMet(pixels.y));    
}

float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;