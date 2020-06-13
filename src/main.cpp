#include "OverallController.h"
#include "GameObj.h"

#include "globals.h"
#include <iostream>
using std::cout;

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>
#include "BaseBall.h"
#include "BasketBall.h"

int main()
{   


    std::vector<GameObj> m_objects;

    auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));
    
    // m_objects.push_back(GameObj(sf::Vector2f(400.f, 0.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
    // m_objects.push_back(GameObj(sf::Vector2f(400.f, 600.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
    // m_objects.push_back(GameObj(sf::Vector2f(0.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));
    // m_objects.push_back(GameObj(sf::Vector2f(800.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Collision Shapes", sf::Style::Default, settings);
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
                if (event.mouseButton.button == sf::Mouse::Left)
                    m_objects.push_back(BaseBall(mouseLoc, (*m_world.get())));
                if (event.mouseButton.button == sf::Mouse::Right)
                    m_objects.push_back(BasketBall(mouseLoc, (*m_world.get())));
               
            }
        }

    }


//=======


	// OverallController game;
	// game.run();


	return EXIT_SUCCESS;
}

