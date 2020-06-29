
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "OverallController.h"
#include "Score.h"

int main()
{   
	Score sco(5);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "sss");

	while (window.isOpen())
	{

		window.clear();
		sco.draw(window);
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

		
		sco.setClock();
		
	}
			
		return 0;
 
 //  auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));


	//OverallController game((*m_world.get()));
	//game.run();
	        

	return EXIT_SUCCESS;
}
