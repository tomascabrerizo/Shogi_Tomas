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
	
	//If at any time we input -1 end the game @temporal
	std::cout << "From cell x:" << std::endl;
	std::cin >> xS;
	if (xS == -1)
	{
		gameRunning = false;
		return;
	}

	//TODO: Make check function for cin >> input
	std::cout << "From cell y:" << std::endl;
	std::cin >> yS;
	if (yS == -1)
	{
		gameRunning = false;
		return;
	}
	//TODO: Make check function for cin >> input
	std::cout << "To cell x:" << std::endl;
	std::cin >> xD;
	if (xD == -1)
	{
		gameRunning = false;
		return;
	}
	//TODO: Make check function for cin >> input
	std::cout << "To cell y:" << std::endl;
	std::cin >> yD;
	if (yD == -1)
	{
		gameRunning = false;
		return;
	}

	if (shogi.getCell(xS, yS)->currentPiece != NULL)
		shogi.getPiece(xS, yS)->move(shogi.getCell(xD, yD));
	else
		std::cout << "there is no piece in that cell" << std::endl;
}

void Game::render()
{
	shogi.render();
}

void Game::checkNumber(int& num)
{
	while (num < 1 || num > 8)
	{
		std::cout << "Enter number between -1(to close) and 8: " << std::endl;
		std::cin >> num;
	}
}


bool Game::isRunning()
{
	return gameRunning;
}
