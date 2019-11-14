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
		bool fistRender = false;
		if (!fistRender)
		{
			ShogiGame.render();
			fistRender = true;
		}
		std::cout << "\n";
		ShogiGame.update();
		std::cout << "\n";
		ShogiGame.render();

	}
	
	return 0;
}