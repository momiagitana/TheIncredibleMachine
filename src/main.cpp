#include "MyListener.h"

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp> //fix

#include "OverallController.h"


int main()
{   
	MyListener listener;
   auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));
   m_world->SetContactListener(&listener);


	OverallController game((*m_world.get()));
	game.run();
	        

	return EXIT_SUCCESS;
}
