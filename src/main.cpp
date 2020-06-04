#include <SFML/Graphics.hpp>

int main()
{
    changes new shit
    

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
    }
}
