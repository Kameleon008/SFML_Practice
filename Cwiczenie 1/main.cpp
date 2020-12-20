#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>


int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception exc)
	{
		std::cout << "\nException: " << exc.what() << std::endl;
	}
	
	return 0;
}