#include <iostream>
#include "Game.h"

int main()
{
	std::cout << "|---------------------------------------|" << std::endl;
	std::cout << "|---------------TOMAS-SHOGI-------------|" << std::endl;
	std::cout << "|---------------------------------------|" << std::endl;

	Game ShogiGame;
	bool fistRender = false;

	while (ShogiGame.isRunning())
	{
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