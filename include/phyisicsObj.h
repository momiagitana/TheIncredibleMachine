#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class PhyisicsObj
{
private:

    
    sf::Vector2f m_loc;
    sf::Vector2f m_dimensions;

    b2Body* m_body = nullptr;
    b2Fixture* m_fixture = nullptr;

    //sf::Color m_color;
   
public:

    void init(b2World* world, const sf::Vector2f& position, const sf::Vector2f& dimensions); //, sf::Color color) 

    PhyisicsObj();
    ~PhyisicsObj();

    b2Body* getBody() const { return m_body; }
    b2Fixture* getFixture() const { return m_fixture; }
    const sf::Vector2f& getDimensions() const { return m_dimensions; }
    //const  Bengine::ColorRGBA8& getColor() const { return m_color; }
};
