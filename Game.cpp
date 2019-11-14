#include "Game.h"

Game::Game()
{
	gameRunning = true;
	//Promote pawn 4 2 to test movement
	shogi.getCell(1, 1)->currentPiece->promote();
	shogi.getCell(8, 0)->currentPiece->promote();
	shogi.getCell(1, 7)->currentPiece->promote();
	playerTurn = PLAYER_UP;
}

Game::~Game()
{
}

void Game::update()
{
	shogi.update();

	bool reinsertPieces = false;
	/*TURN PLAYER UP*/
	if (playerTurn == PLAYER_UP)
	{
		std::string playerUP = "\n|-----------------|\n"
								"|----PLAYER_UP----|\n"
								"|-----------------|";

		std::cout << playerUP << std::endl;
		if (shogi.getReInsertPU())
		{
			std::cout << "PlayerU: Can reinsert a piece, do you want to reinsert it?" << std::endl;

			char answer;
			std::cin >> answer;
			if (answer == 'y')
			{
				reinsertPieces = true;
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
		if(!reinsertPieces)
		{
			/*Cell X and Y tmp variables*/
			int xS, yS; /*Source cell*/
			int xD, yD; /*Destination cell*/
			bool moveSucces = false;

			while (!moveSucces)
			{
				xS = checkedNumber("\nFrom Cell X: ");
				yS = checkedNumber("From Cell Y: ");

				xD = checkedNumber("To Cell X: ");
				yD = checkedNumber("To Cell Y: ");

				if (shogi.getCell(xS, yS)->currentPiece != NULL)
				{
					if (shogi.getPiece(xS, yS)->getPlayer() == PLAYER_UP)
					{
						if (shogi.getPiece(xS, yS)->move(shogi.getCell(xD, yD)))
						{
							moveSucces = true;
						}
					}
					else
					{
						std::cout << "This is a enemy piece" << std::endl;
					}
				}
				else
				{
					std::cout << "There is no piece in that cell" << std::endl;
				}
			}
			moveSucces = false;

		}
		playerTurn = PLAYER_DOWN;
	}
	else
	{
		/*PLAYER BOTTOM*/
		std::string playerBOTTOM = "\n|-----------------|\n"
									"|--PLAYER_BOTTOM--|\n"
									"|-----------------|";
											

		std::cout << playerBOTTOM << std::endl;
		if (shogi.getReInsertPB())
		{
			std::cout << "PlayerB: can reinsert a piece, do you want to reinsert it?" << std::endl;

			char answer;
			std::cin >> answer;
			if (answer == 'y')
			{
				reinsertPieces = true;
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
		if(!reinsertPieces)
		{
			/*Cell X and Y tmp variables*/
			int xS, yS; /*Source cell*/
			int xD, yD; /*Destination cell*/
			bool moveSucced = false;

			while (!moveSucced)
			{
				xS = checkedNumber("\nFrom Cell X: ");
				yS = checkedNumber("From Cell Y: ");

				xD = checkedNumber("To Cell X: ");
				yD = checkedNumber("To Cell Y: ");

				if (shogi.getCell(xS, yS)->currentPiece != NULL)
				{
					if (shogi.getPiece(xS, yS)->getPlayer() == PLAYER_DOWN)
					{
						if (shogi.getPiece(xS, yS)->move(shogi.getCell(xD, yD)))
						{
							moveSucced = true;
						}
					}
					else
					{
						std::cout << "This is a enemy piece" << std::endl;
					}
				}
				else
				{
					std::cout << "There is no piece in that cell" << std::endl;
				}
			}
			moveSucced = false;
		}
		playerTurn = PLAYER_UP;
	}

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
