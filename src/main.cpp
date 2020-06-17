

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

#include "OverallController.h"

#include "Toolbar.h"
using std::pair;

using toolbarPair = std::pair<GameObject_t, int>;
using toolbarObjects = std::vector<toolbarPair>;

int main()
{   

   auto m_world = std::make_unique<b2World>(b2Vec2(0,9.81));


    Level lvl;
	OverallController game(lvl, (*m_world.get()));
	game.run();


	return EXIT_SUCCESS;
}



