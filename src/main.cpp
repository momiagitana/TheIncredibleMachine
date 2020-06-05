#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <PhyisicsObj.h>
#include <vector>






int main()
{   

    auto world = std::make_unique<b2World>(b2Vec2(0,9.81));

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 300.0f);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    sf::RectangleShape ground;
    ground.setFillColor(sf::Color::Blue);
    ground.setSize(sf::Vector2f(250.0f,1.0f));
    b2Vec2 groundPosition = groundBody->GetPosition();
    float groundAngle = groundBody->GetAngle();
    ground.setPosition(groundPosition.x, groundPosition.y);
    ground.setRotation(groundAngle);
    


    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(50.0f, 70.0f);
    b2Body* body = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f; 
    body->CreateFixture(&fixtureDef);

    sf::RectangleShape rect;
    rect.setFillColor(sf::Color::White);
    rect.setSize(sf::Vector2f(20.0f,20.0f));

    auto window = sf::RenderWindow(sf::VideoMode(600, 600), "Example");

    while (window.isOpen())
    {
        world->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        rect.setPosition(position.x, position.y);
        rect.setRotation(angle);
        window.clear();
        window.draw(rect);
        window.draw(ground);
        window.display();


        
		sf::Event event;
		while (window.pollEvent(event))
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

