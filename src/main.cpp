#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

int main()
{
   
    auto window = sf::RenderWindow(sf::VideoMode(300, 300), "Example");

    while (window.isOpen())
    {
        window.clear();
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

        b2World world(b2Vec2(1,1));
    }
}
