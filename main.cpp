#include <iostream>
#include "Game.h"

int main()
{
	std::cout << "|----------------------|" << std::endl;
	std::cout << "|      Tom's Shogi!    |" << std::endl;
	std::cout << "|----------------------|" << std::endl;

	Game ShogiGame;

	while (ShogiGame.isRunning())
	{
		ShogiGame.render();
		ShogiGame.update();
	}
	
	return 0;
}