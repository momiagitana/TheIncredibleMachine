#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <PhyisicsObj.h>
#include <vector>

int main()
{

    std::vector<PhyisicsObj> boxes;

    auto world = std::make_unique<b2World>(b2Vec2(0,-9.81));

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,-10.0f);
    b2Body* body = world->CreateBody(&groundBodyDef);
    b2PolygonShape boxShape;
    boxShape.SetAsBox(50.0f,10.0f);
    body->CreateFixture(&boxShape, 0.0f); //0 density coz its static

    PhyisicsObj box;
    box.init(world.get(), sf::Vector2f(0.0f,14.0f), sf::Vector2f(15.0f,15.0f));
    boxes.push_back(box);


    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f(box.getBody()->GetPosition().x, box.getBody()->GetPosition().y));
    rect.setFillColor(sf::Color::White);
    rect.setSize(sf::Vector2f(20.0f,20.0f));

    auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

    while (window.isOpen())
    {
        window.clear();
        window.draw(rect);
        window.display();

        
        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

    }
}
