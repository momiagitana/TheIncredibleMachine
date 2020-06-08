#include <SFML/Graphics.hpp>
#include "testingAnimation.h"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

    TestingAnimation t;

    while (window.isOpen())
    {

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                t.drawAnimation(window);
                break;
            }
        }
    }
}
