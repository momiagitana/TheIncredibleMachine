
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


#include "globals.h"
#include "ResourceManager.h"


int main()
{
    toolbarPair p1(GameObject_t::baseBall, 4);
    toolbarPair p2(GameObject_t::bowlingBall, 3);
    toolbarPair p3(GameObject_t::basketBall, 8);
    toolbarObjects v({});

    Toolbar t(v);


    sf::RenderWindow window(sf::VideoMode(800, 800), "example");
    sf::Event e;

    while (window.isOpen())
    {
        auto ml = sf::Mouse::getPosition(window);
        window.clear();
        t.draw(window);
        window.display();

        while (window.pollEvent(e))
        {
            switch (e.type)
            {
                      case sf::Event::Closed:
                      {

                        window.close();
                        break;
                      }


            case sf::Event::MouseButtonPressed:
            {
                switch (e.key.code)
                {
                case sf::Mouse::Left:
                {
                    if (t.clickedOnMe(sf::Vector2f(ml.x, ml.y)))
                    {
                        cout << "in board\n";
                    }
                    else
                    {
                        cout << "not in board\n";
                    }

                    break;
                }
                //
                break;

                case sf::Mouse::Right:
                {

                    GameObject_t temp = t.handelclick(sf::Vector2f(ml.x, ml.y));
                    if (temp == play)
                    {
                        cout << "play \n";
                    }
                    else if (temp == bowlingBall)
                    {
                        cout << "bowling \n";
                    }
                    
                    else if(temp == none)
                    {
                        cout << "none\n";
                    }
                    else if (temp == basketBall)
                    {
                        cout << "basket\n";
                    }
                    else if (temp == baseBall)
                    {
                        cout << "base\n";
                    }
                    break;
                }
                break;
                }

            break;

            case sf::Event::KeyPressed:
            {
                switch (e.key.code)
                {
                case sf::Keyboard::A:
                {
                    cout << "peform Add\n";
                    t.add(p3);
                    break;
                }
                case sf::Keyboard::D:
                {
                    cout << "peform Add\n";
                    t.Delete(GameObject_t::basketBall);
                    break;
                }
                case sf::Keyboard::P:
                {
                    cout << "peform Add\n";
                    t.add(p2);
                    break;
                }
                case sf::Keyboard::O:
                {
                    cout << "peform Add\n";
                    t.Delete(GameObject_t::bowlingBall);
                    break;
                }
                case sf::Keyboard::I:
                {
                    cout << "peform Add\n";
                    t.Delete(GameObject_t::baseBall);
                    break;
                }
                case sf::Keyboard::U:
                {
                    cout << "peform Add\n";
                    t.add(p1);
                    break;
                }
                }
                break;
            }
            }
            }




            ////   std::vector<GameObj> m_objects;

            //  auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));
            //  
            ////   // m_objects.push_back(GameObj(sf::Vector2f(400.f, 0.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
            ////   // m_objects.push_back(GameObj(sf::Vector2f(400.f, 600.f), sf::Vector2f(800.f, 50.f), &brickText, false, (*m_world.get())));
            ////   // m_objects.push_back(GameObj(sf::Vector2f(0.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));
            ////   // m_objects.push_back(GameObj(sf::Vector2f(800.f, 300.f), sf::Vector2f(50.f, 800.f), &brickText, false, (*m_world.get())));

            //  sf::ContextSettings settings;
            //  settings.antialiasingLevel = 8;

            //  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Collision Shapes", sf::Style::Default, settings);
            //  window.setFramerateLimit(60);

            //  Level lvl;
            //  LevelController lvlCtrl(lvl, (*m_world.get()), window);

            //  lvlCtrl.run();



               ////// OverallController game;
               ////// game.run();


        }

    }
   return EXIT_SUCCESS;
}
