

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "OverallController.h"


int main()
{   

   auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));


	OverallController game((*m_world.get()));
	game.run();
	        

	return EXIT_SUCCESS;
}
