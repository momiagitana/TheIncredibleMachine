#include "OverallController.h"
#include "Toolbar.h"
#include "Globals.h"
#include <iostream>
using std::cout;

int main()
{
	
	try
	{
	//david was here
	srand((int)time(NULL));
	OverallController game;
	game.run();

	}
	catch (const std::exception&e)
	{
		cout << e.what() << "\n";
	}

	EXIT_SUCCESS;
}
