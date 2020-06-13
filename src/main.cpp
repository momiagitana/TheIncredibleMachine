#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>
#include <gameObj.h>

float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

#define TIMESTEP 1.0f/60.0f     // Refresh time
#define VELITER 10              // Number of iterations per tick to calculate speed
#define POSITER 10              // Number tick iterations to calculate the position


int main()
{   
    sf::Texture windmill;
    windmill.loadFromFile("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/wind.png");
    
    sf::Texture brickText;
    brickText.loadFromFile("/Users/arielzingman/OOP2/EX5TheIncredibleMachine/TheIncredibleMachine/resources/brick.png");

    sf::Sprite brick;
    brick.setTexture(brickText);

    std::vector<GameObj> m_objects;

    auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));
    
    m_objects.push_back(GameObj(sf::Vector2f(400.f, 0.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
    m_objects.push_back(GameObj(sf::Vector2f(400.f, 600.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
    m_objects.push_back(GameObj(sf::Vector2f(0.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));
    m_objects.push_back(GameObj(sf::Vector2f(800.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));

    // GameObj one(sf::Vector2f(250.0f,70.0f),sf::Vector2f(50.0f,50.0f), &text, true, world.get());
    // GameObj base(sf::Vector2f(100.0f, 300.0f),sf::Vector2f(300.0f,100.0f), &text, false, world.get());
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Collision Shapes", sf::Style::Default, settings);
    window.setFramerateLimit(60);

   

    while (window.isOpen())
    {
        window.clear(sf::Color::Transparent);

        m_world->Step(TIMESTEP, VELITER, POSITER);

        for(auto& obj : m_objects)
            obj.draw(window);

        window.display();


        
		sf::Event event;
		while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonReleased:

                auto mouseLoc = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                if (event.mouseButton.button == sf::Mouse::Right)
                    m_objects.push_back(GameObj(mouseLoc, sf::Vector2f(50.f, 50.f), &windmill, false, (*m_world.get())));
                if (event.mouseButton.button == sf::Mouse::Left)
                    m_objects.push_back(GameObj(mouseLoc, sf::Vector2f(50.f, 50.f), &windmill, true, (*m_world.get())));
            }
        }

    }
}

