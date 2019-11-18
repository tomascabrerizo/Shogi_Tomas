#include "Game.h"

#ifdef _WIN32

#define Clear() system("CLS");

#endif 

#ifdef __linux__

#define Clear() system("clear");

#endif

#ifdef __APPLE__

#define Clear() system("clear");

#endif 


Game::Game()
{
	gameRunning = true;
	/*Initllize Board*/
	shogi.initBoard();
	playerTurn = PLAYER_UP;
}

Game::~Game()
{
}

void Game::update()
{
	bool moveSucces = false; /*flag to check is the move was succesful*/

	/*TURN PLAYER UP*/
	if (playerTurn == PLAYER_UP)
	{
		std::string playerUP = "|-----------------|\n|----PLAYER_UP----|\n|-----------------|";
		std::cout << playerUP << std::endl;
		while (!moveSucces)
		{
			if (gameInput.checkForCommand())
			{
				switch (gameInput.getCommandType())
				{
				case MOVE:
					if (shogi.getCell(gameInput.getXSource(), gameInput.getYSource())->currentPiece != NULL)
					{
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_UP)
						{
							if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->move(shogi.getCell(gameInput.getXDest(), gameInput.getYDest())))
							{
								moveSucces = true;
								//commandSucces = true;
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
					break;
				case PROMOTE:

					if (shogi.getCell(gameInput.getXSource(), gameInput.getYSource())->currentPiece != NULL)
					{
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_UP)
						{
							if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->promote())
							{
								moveSucces = true;
							}
							else
							{
								std::cout << "Cannot promote this piece yet" << std::endl;
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

					break;
				case INSERT:
					for (int i = 0; i < shogi.getPlayerUp()->size(); i++)
					{
						if (shogi.getPlayerUp()->at(i)->getPosition() == NULL)
						{
							//TODO: check for piece type and check if the position to set is valid
							shogi.getPlayerUp()->at(i)->setPosition(&(shogi.getBoard()[gameInput.getXSource() + gameInput.getYSource() * 9]));
							shogi.getPlayerUp()->at(i)->getPosition()->kanji = shogi.getPlayerUp()->at(i)->getKanjiTop();
							moveSucces = true;
							break;
						}
					}
					break;
				default:
					break;
				}
			}
		}
		playerTurn = PLAYER_DOWN;
	}
	else
	{
		/*PLAYER BOTTOM*/
		std::string playerBOTTOM = "|-----------------|\n|--PLAYER_BOTTOM--|\n|-----------------|";									
		std::cout << playerBOTTOM << std::endl;
		while (!moveSucces)
		{
			if (gameInput.checkForCommand())
			{
				switch (gameInput.getCommandType())
				{
				case MOVE:
					if (shogi.getCell(gameInput.getXSource(), gameInput.getYSource())->currentPiece != NULL)
					{
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_DOWN)
						{
							if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->move(shogi.getCell(gameInput.getXDest(), gameInput.getYDest())))
							{
								moveSucces = true;
								//commandSucces = true;
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
					break;
				case PROMOTE:

					if (shogi.getCell(gameInput.getXSource(), gameInput.getYSource())->currentPiece != NULL)
					{
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_DOWN)
						{
							if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->promote())
							{
								moveSucces = true;
							}
							else
							{
								std::cout << "Cannot promote this piece yet" << std::endl;
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

					break;
				case INSERT:
					for (int i = 0; i < shogi.getPlayerUp()->size(); i++)
					{
						if (shogi.getPlayerBottom()->at(i)->getPosition() == NULL)
						{
							//TODO: check for piece type and check if the position to set is valid
							shogi.getPlayerBottom()->at(i)->setPosition(&(shogi.getBoard()[gameInput.getXSource() + gameInput.getYSource() * 9]));
							shogi.getPlayerBottom()->at(i)->getPosition()->kanji = shogi.getPlayerBottom()->at(i)->getKanjiBottom();
							moveSucces = true;
							break;
						}
					}
					break;
				default:
					break;
				}
			}
		}
		playerTurn = PLAYER_UP;
	}

	//At the start of every turn, update the shogi table to get all the laters changes
	shogi.update();
}

void Game::render()
{
	Clear();
	std::cout << "|---------------------------------------|" << std::endl;
	std::cout << "|---------------TOMAS-SHOGI-------------|" << std::endl;
	std::cout << "|---------------------------------------|" << std::endl;
	shogi.render();
}

int Game::checkedNumber(const char* message)
{
	//Checks if the player input is correct
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
