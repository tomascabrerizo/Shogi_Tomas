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
	playerTurn = PLAYER_TOP;
	playerBottomWins = false;
	playerTopWins = false;


	//Get the pointers to the kings pieces
	for (int i = 0; i < shogi.getPlayerTop()->size(); i++)
	{
		if (shogi.getPlayerTop()->at(i)->getName() == KING)
		{
			kingTop = static_cast<king*>(shogi.getPlayerTop()->at(i));
		}
	}


	for (int i = 0; i < shogi.getPlayerBottom()->size(); i++)
	{
		if (shogi.getPlayerBottom()->at(i)->getName() == KING)
		{
			kingBottom = static_cast<king*>(shogi.getPlayerBottom()->at(i));
		}
	}
}

Game::~Game()
{
}

void Game::update()
{
	bool moveSucces = false; /*flag to check is the move was succesful*/
	bool kingInCheck = false; /*flag to check if the king is not in ckech after his turn*/

	/*TURN PLAYER UP*/
	if (playerTurn == PLAYER_TOP)
	{
		std::string playerUP = "|-----------------|\n|----PLAYER_UP----|\n|-----------------|";
		std::cout << playerUP << std::endl;
		while (!moveSucces || kingInCheck)
		{
			if (gameInput.checkForCommand())
			{
				switch (gameInput.getCommandType())
				{
				case MOVE:
					if (shogi.getCell(gameInput.getXSource(), gameInput.getYSource())->currentPiece != NULL)
					{
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_TOP)
						{
							if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->move(shogi.getCell(gameInput.getXDest(), gameInput.getYDest())))
							{
								moveSucces = true;
								/*Checks if the top king is still in check at the end of the turn, if it is check mate*/
								if (kingTop != NULL && kingTop->isInCheck())
								{
									kingInCheck = true;

									/*If after the move the king is still in check, force to reverse the movement*/
									shogi.getPiece(gameInput.getXDest(), gameInput.getYDest())->forceMove(shogi.getCell(gameInput.getXSource(), gameInput.getYSource()));
									
									//HADCODE the bug where if the movement capture a enemy but the king is still in check
									//HADCODE need to reinsert the capture piece
									if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getLastPieceCaptured() != NULL)
									{
										shogi.getCell(gameInput.getXDest(), gameInput.getYDest())->currentPiece =
											shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getLastPieceCaptured();
										shogi.getCell(gameInput.getXDest(), gameInput.getYDest())->kanji = shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getKanjiBottom();

										shogi.getPiece(gameInput.getXDest(), gameInput.getYDest())->setCapture(false);
										//shogi.getCell(gameInput.getXDest(), gameInput.getYDest())->currentPiece = NULL;
										shogi.getPiece(gameInput.getXDest(), gameInput.getYDest())->forceSetPosition(shogi.getCell(gameInput.getXDest(), gameInput.getYDest()));
									}
									
								}
								else
								{
									kingInCheck = false;
								}
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
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_TOP)
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
					for (int i = 0; i < shogi.getPlayerTop()->size(); i++)
					{
						if (shogi.getPlayerTop()->at(i)->getPosition() == NULL && 
							shogi.getPlayerTop()->at(i)->getId() == gameInput.getPieceType())
						{

							if (shogi.getPlayerTop()->at(i)->insertPiece(&(shogi.getBoard()[gameInput.getXSource() + gameInput.getYSource() * 9])))
							{
								shogi.getPlayerTop()->at(i)->getPosition()->kanji = shogi.getPlayerTop()->at(i)->getKanjiTop();
								moveSucces = true;
							}
							else
							{
								std::cout << "Cannot insert this piece there" << std::endl;
							}
							/*
							//TODO: check for piece type and check if the position to set is valid
							shogi.getPlayerTop()->at(i)->setPosition(&(shogi.getBoard()[gameInput.getXSource() + gameInput.getYSource() * 9]));
							shogi.getPlayerTop()->at(i)->getPosition()->kanji = shogi.getPlayerTop()->at(i)->getKanjiTop();
							
							*/
							break;
						}
					}
					break;
				case END:
					gameRunning = false;
					moveSucces = true;
					kingInCheck = false;
					break;
				default:
					break;
				}
			}
		}
		
		/*Check for check Mate*/
		/*Cast to king to acces to checkMate method*/
		if (kingBottom != NULL && kingBottom->isInCheckMate())
		{
			/*Player Up wins*/
			playerTopWins = true;
			gameRunning = false;
		}
		
		playerTurn = PLAYER_BOTTOM;
	}
	else
	{
		/*PLAYER BOTTOM*/
		std::string playerBOTTOM = "|-----------------|\n|--PLAYER_BOTTOM--|\n|-----------------|";									
		std::cout << playerBOTTOM << std::endl;
		while (!moveSucces || kingInCheck)
		{
			if (gameInput.checkForCommand())
			{
				switch (gameInput.getCommandType())
				{
				case MOVE:
					if (shogi.getCell(gameInput.getXSource(), gameInput.getYSource())->currentPiece != NULL)
					{
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_BOTTOM)
						{
							if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->move(shogi.getCell(gameInput.getXDest(), gameInput.getYDest())))
							{
								moveSucces = true;
								/*Checks if the top king is still in check at the end of the turn, if it is check mate*/
								if (kingBottom != NULL && kingBottom->isInCheck())
								{
									kingInCheck = true;

									/*If after the move the king is still in check, force to reverse the movement*/
									shogi.getPiece(gameInput.getXDest(), gameInput.getYDest())->forceMove(shogi.getCell(gameInput.getXSource(), gameInput.getYSource()));

									//HADCODE the bug where if the movement capture a enemy but the king is still in check
									//HADCODE need to reinsert the capture piece
									if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getLastPieceCaptured() != NULL)
									{
										shogi.getCell(gameInput.getXDest(), gameInput.getYDest())->currentPiece =
											shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getLastPieceCaptured();
										shogi.getCell(gameInput.getXDest(), gameInput.getYDest())->kanji = shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getKanjiTop();

										shogi.getPiece(gameInput.getXDest(), gameInput.getYDest())->setCapture(false);
										//shogi.getCell(gameInput.getXDest(), gameInput.getYDest())->currentPiece = NULL;
										shogi.getPiece(gameInput.getXDest(), gameInput.getYDest())->forceSetPosition(shogi.getCell(gameInput.getXDest(), gameInput.getYDest()));
									}
								}
								else
								{
									kingInCheck = false;
								}
							}
							if (kingBottom != NULL) kingBottom->updateEnemyPosition();
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
						if (shogi.getPiece(gameInput.getXSource(), gameInput.getYSource())->getPlayer() == PLAYER_BOTTOM)
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
					for (int i = 0; i < shogi.getPlayerBottom()->size(); i++)
					{
						if (shogi.getPlayerBottom()->at(i)->getPosition() == NULL &&
							shogi.getPlayerBottom()->at(i)->getId() == gameInput.getPieceType())
						{
							if (shogi.getPlayerBottom()->at(i)->insertPiece(&(shogi.getBoard()[gameInput.getXSource() + gameInput.getYSource() * 9])))
							{
								shogi.getPlayerBottom()->at(i)->getPosition()->kanji = shogi.getPlayerBottom()->at(i)->getKanjiBottom();
								moveSucces = true;
							}
							else
							{
								std::cout << "Cannot insert this piece there" << std::endl;
							}
							/*
							//TODO: check for piece type and check if the position to set is valid
							shogi.getPlayerTop()->at(i)->setPosition(&(shogi.getBoard()[gameInput.getXSource() + gameInput.getYSource() * 9]));
							shogi.getPlayerTop()->at(i)->getPosition()->kanji = shogi.getPlayerTop()->at(i)->getKanjiTop();

							*/
							break;
						}
					}
					break;
				case END:
					gameRunning = false;
					moveSucces = true;
					kingInCheck = false;
					break;
				default:
					break;
				}
			}
		}
		
		if (kingTop != NULL && kingTop->isInCheckMate())
		{
			/*Player Up wins*/
			playerBottomWins = true;
			gameRunning = false;
		}

		playerTurn = PLAYER_TOP;
	}

	shogi.update();
}

void Game::render()
{
	Clear();
	std::cout << "|---------------------------------------|" << std::endl;
	std::cout << "|---------------TOMAS-SHOGI-------------|" << std::endl;
	std::cout << "|---------------------------------------|" << std::endl;
	shogi.render();
	if (playerBottomWins)
	{
		std::cout << "|---------------------------------------|" << std::endl;
		std::cout << "|---------------CHECK MATE--------------|" << std::endl;
		std::cout << "|-----------BOTTOM-PLAYER-WINS----------|" << std::endl;
		std::cout << "|---------------------------------------|" << std::endl;
	}
	if (playerTopWins)
	{
		std::cout << "|---------------------------------------|" << std::endl;
		std::cout << "|---------------CHECK MATE--------------|" << std::endl;
		std::cout << "|-------------UP-PLAYER-WINS------------|" << std::endl;
		std::cout << "|---------------------------------------|" << std::endl;
	}
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
