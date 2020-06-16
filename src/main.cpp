
//#include "globals.h"
//#include <iostream>
//using std::cout;

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
//#include <vector>

#include "LevelController.h"
//#include "Level.h"

#include "Toolbar.h"
using std::pair;

using toolbarPair = std::pair<GameObject_t, int>;
using toolbarObjects = std::vector<toolbarPair>;

int main()
{   
    std::vector<std::pair<GameObject_t, int>> v;
    v.emplace_back(std::pair<GameObject_t, int>(GameObject_t::baseBall, 2));
    v.emplace_back(std::pair<GameObject_t, int>(GameObject_t::basketBall, 2));
    Toolbar t(v);

  /*  Button b(GameObject_t::baseBall, 5);
    b.setposition(sf::Vector2f(200,200));*/

    sf::RenderWindow window(sf::VideoMode(800, 800), "ss");
    sf::Event e;

    while (window.isOpen())
    {

        window.clear();
        t.draw(window);
        window.display();

        while (window.pollEvent(e))
        {
            switch (e.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
    }




 //   std::vector<GameObj> m_objects;

 //   auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));
 //   
 //   // m_objects.push_back(GameObj(sf::Vector2f(400.f, 0.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
 //   // m_objects.push_back(GameObj(sf::Vector2f(400.f, 600.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
 //   // m_objects.push_back(GameObj(sf::Vector2f(0.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));
 //   // m_objects.push_back(GameObj(sf::Vector2f(800.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));

 //   sf::ContextSettings settings;
 //   settings.antialiasingLevel = 8;

 //   sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Collision Shapes", sf::Style::Default, settings);
 //   window.setFramerateLimit(60);

 //   Level lvl;
 //   LevelController lvlCtrl(lvl, (*m_world.get()), window);

 //   lvlCtrl.run();



	//// OverallController game;
	//// game.run();


	return EXIT_SUCCESS;
}



