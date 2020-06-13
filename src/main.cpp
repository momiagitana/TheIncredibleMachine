#include "OverallController.h"

#include "Toolbar.h"
#include "Globals.h"
#include <iostream>
using std::cout;

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

int main()
{

	OverallController game;
	game.run();

	}
	catch (const std::exception&e)
	{
		cout << e.what() << "\n";
	}

	EXIT_SUCCESS;
}