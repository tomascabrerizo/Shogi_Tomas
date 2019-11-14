#include "Game.h"

Game::Game()
{
	gameRunning = true;
	//Promote pawn 4 2 to test movement
	shogi.getCell(1, 1)->currentPiece->promote();
	shogi.getCell(8, 0)->currentPiece->promote();
	shogi.getCell(1, 7)->currentPiece->promote();
}

Game::~Game()
{
}

void Game::update()
{
	shogi.update();


	/*PLAYER UP*/
	if (shogi.getReInsertPU())
	{
		std::cout << "PlayerU: Can reinsert a piece, do you want to reinsert it?" << std::endl;

		char answer;
		std::cin >> answer;
		if (answer == 'y')
		{
			int x, y;
			std::cout << "Chose the cell where you want to re insert the piece: " << std::endl;
			std::cin >> x >> y;

			for (int i = 0; i < shogi.getPlayer2()->size(); i++)
			{
				if (shogi.getPlayer2()->at(i)->getPosition() == NULL)
				{
					shogi.getPlayer2()->at(i)->setPosition(&(shogi.getBoard()[x + y * 9]));
					shogi.getPlayer2()->at(i)->getPosition()->kanji = shogi.getPlayer2()->at(i)->getKanjiTop();
				}
			}
		}

	}

	/*PLAYER BOTTOM*/
	if (shogi.getReInsertPB())
	{
		std::cout << "PlayerB: can reinsert a piece, do you want to reinsert it?" << std::endl;

		char answer;
		std::cin >> answer;
		if (answer == 'y')
		{
			int x, y;
			std::cout << "Chose the cell where you want to re insert the piece: " << std::endl;
			std::cin >> x >> y;

			for (int i = 0; i < shogi.getPlayer1()->size(); i++)
			{
				if (shogi.getPlayer1()->at(i)->getPosition() == NULL)
				{
					shogi.getPlayer1()->at(i)->setPosition(&(shogi.getBoard()[x + y * 9]));
					shogi.getPlayer1()->at(i)->getPosition()->kanji = shogi.getPlayer1()->at(i)->getKanjiBottom();
				}
			}
		}
	}

	/*Cell X and Y tmp variables*/
	int xS, yS; /*Source cell*/
	int xD, yD; /*Destination cell*/
	
	xS = checkedNumber("\nFrom Cell X: ");
	yS = checkedNumber("From Cell Y: ");

	xD = checkedNumber("To Cell X: ");
	yD = checkedNumber("To Cell Y: ");

	if (shogi.getCell(xS, yS)->currentPiece != NULL)
		shogi.getPiece(xS, yS)->move(shogi.getCell(xD, yD));
	else
		std::cout << "There is no piece in that cell" << std::endl;
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

			if (num >= 0 && num <= 8)
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
