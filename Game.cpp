#include "Game.h"

Game::Game()
{
	gameRunning = true;
}

Game::~Game()
{
}

void Game::update()
{
	/*Cell X and Y tmp variables*/
	int xS, yS; /*Source cell*/
	int xD, yD; /*Destination cell*/
	
	xS = checkedNumber("From Cell X: ");
	yS = checkedNumber("From Cell Y: ");

	xD = checkedNumber("To Cell X: ");
	yD = checkedNumber("To Cell Y: ");

	if (shogi.getCell(xS, yS)->currentPiece != NULL)
		shogi.getPiece(xS, yS)->move(shogi.getCell(xD, yD));
	else
		std::cout << "there is no piece in that cell" << std::endl;
}

void Game::render()
{
	shogi.render();
}

int Game::checkedNumber(const char* message)
{
	while (true)
	{
		std::cout << message << std::endl;
		int num;
		std::cin >> num;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if (num >= -1 && num <= 8)
			{
				return num;
			}
		}
	}
}


bool Game::isRunning()
{
	return gameRunning;
}
