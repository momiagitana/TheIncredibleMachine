
//#include "globals.h"
//#include <iostream>
//using std::cout;

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
//#include <vector>

#include "LevelController.h"
//#include "Level.h"

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

    Level lvl;
    LevelController lvlCtrl(lvl, (*m_world.get()), window);

    lvlCtrl.run();



	// OverallController game;
	// game.run();


	return EXIT_SUCCESS;
}

