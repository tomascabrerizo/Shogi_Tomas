#include "board.h"

Board::Board()
{
	//Initiallize the Board
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			board[x + y * 9].x = x;
			board[x + y * 9].y = y;
			board[x + y * 9].currentPiece = NULL;
			board[x + y * 9].kanji = "    |";
		}
	}

	reInsertPB = false;
	reInsertPU = false;
}

Board::~Board()
{
	//free the heap before end
	for (piece* tmp : playerBottom)
	{
		delete tmp;
	}
	for (piece* tmp : playerUp)
	{
		delete tmp;
	}
}


void Board::initBoard()
{
	/**************************************************/
	/*initialized player pieces positions on the board*/
	/**************************************************/
	/*Allocate the pieces on the heap to achive polymorphism*/

	//player1 and player2 kings;
	playerBottom.push_back(new king(&board[4 + 8 * 9], PLAYER_DOWN));
	playerUp.push_back(new king(&board[4 + 0 * 9], PLAYER_UP));

	//player1 and player2 rook;
	playerBottom.push_back(new rook(&board[7 + 7 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	playerUp.push_back(new rook(&board[1 + 1 * 9], PLAYER_UP, &board[0 + 0 * 9]));

	//Player1 and player2 pawns
	for (int i = 0; i < 9; i++)
	{
		playerBottom.push_back(new pawn(&board[i + 6 * 9], PLAYER_DOWN));
		playerUp.push_back(new pawn(&board[i + 2 * 9], PLAYER_UP));
	}

	//Player1 and player2 bishop
	playerBottom.push_back(new bishop(&board[1 + 7 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	playerUp.push_back(new bishop(&board[7 + 1 * 9], PLAYER_UP, &board[0 + 0 * 9]));

	//Player1 and Player 2 Gold Generlars
	playerBottom.push_back(new GoldGeneral(&board[3 + 8 * 9], PLAYER_DOWN));
	playerBottom.push_back(new GoldGeneral(&board[5 + 8 * 9], PLAYER_DOWN));
	playerUp.push_back(new GoldGeneral(&board[3 + 0 * 9], PLAYER_UP));
	playerUp.push_back(new GoldGeneral(&board[5 + 0 * 9], PLAYER_UP));

	//Player1 and Player 2 Silver Generlars
	playerBottom.push_back(new SilverGeneral(&board[2 + 8 * 9], PLAYER_DOWN));
	playerBottom.push_back(new SilverGeneral(&board[6 + 8 * 9], PLAYER_DOWN));
	playerUp.push_back(new SilverGeneral(&board[2 + 0 * 9], PLAYER_UP));
	playerUp.push_back(new SilverGeneral(&board[6 + 0 * 9], PLAYER_UP));

	//Player1 and Player2 knights
	playerBottom.push_back(new Knight(&board[1 + 8 * 9], PLAYER_DOWN));
	playerBottom.push_back(new Knight(&board[7 + 8 * 9], PLAYER_DOWN));
	playerUp.push_back(new Knight(&board[1 + 0 * 9], PLAYER_UP));
	playerUp.push_back(new Knight(&board[7 + 0 * 9], PLAYER_UP));

	//Player1 and Player2 Lancers
	playerBottom.push_back(new Lance(&board[0 + 8 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	playerBottom.push_back(new Lance(&board[8 + 8 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	playerUp.push_back(new Lance(&board[0 + 0 * 9], PLAYER_UP, &board[0 + 0 * 9]));
	playerUp.push_back(new Lance(&board[8 + 0 * 9], PLAYER_UP, &board[0 + 0 * 9]));
}

void Board::update()
{
	/*Check for new captured pieces, if one piece is capture change sides*/
	for (int i = 0; i < playerBottom.size(); i++)
	{
		/*Check if there are any pieces outside the board*/
		playerBottom[i]->getPosition() == NULL ? reInsertPB = true : reInsertPB = false;

		if (playerBottom[i]->isCapture())
		{
			playerBottom[i]->setCapture(false);
			playerUp.push_back(playerBottom[i]);
			std::cout << "One " << playerBottom[i]->getName() << " change side " << std::endl;
			playerBottom.erase(playerBottom.begin()+i);
		}
	}
	/*Check for new captured pieces, if one piece is capture change sides*/
	for (int i = 0; i < playerUp.size(); i++)
	{
		/*Check if there are any pieces outside the board*/
		playerUp[i]->getPosition() == NULL ? reInsertPU = true : reInsertPU = false;

		if (playerUp[i]->isCapture())
		{
			playerUp[i]->setCapture(false);
			playerBottom.push_back(playerUp[i]);
			std::cout << "One " << playerUp[i]->getName() << " change side " << std::endl;
			playerUp.erase(playerUp.begin() + i);
		}	
	}
}

void Board::render()
{
	//Render the console characters
	for (int y = 0; y < 11; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (y == 1 && x == 0)
			{
				std::cout << " ## |";
			}
			else if (x == 0 && y > 1)
			{
				std::cout << " " << y - 2 << "  |";
			}
			else if (y == 1 && x > 0)
			{
				std::cout << " " << x - 1 << "  |";
			}
			else if (y > 1 && x > 0)
			{
				std::cout << board[(x - 1) + (y - 2) * 9].kanji;
			}
		}
		std::cout << "\n";
		if (y == 0 || y == 10)
			std::cout << "--------------------------------------------------\n";
		else
			std::cout << "----|----|----|----|----|----|----|----|----|----|\n";
	}

	/*RENDER PIECES CONTER*/
	/*PLAYER UP*/
	int pC = 0, rC = 0, bC = 0, nC = 0, kC = 0, sgC = 0, ggC = 0, lC = 0;
	/*Not inssert pieces*/
	int npC = 0, nrC = 0, nbC = 0, nnC = 0, nkC = 0, nsgC = 0, nggC = 0, nlC = 0;

	for (int i = 0; i < playerUp.size(); i++)
	{
		if (playerUp[i]->getName() == PAWN)
		{
			pC++;
			if (playerUp[i]->getPosition() == NULL) npC++;
		}
		if (playerUp[i]->getName() == ROOK)
		{
			rC++;
			if (playerUp[i]->getPosition() == NULL) nrC++;
		}
		if (playerUp[i]->getName() == BISHOP)
		{
			bC++;
			if (playerUp[i]->getPosition() == NULL) nbC++;
		}
		if (playerUp[i]->getName() == KNIGHT)
		{
			nC++;
			if (playerUp[i]->getPosition() == NULL) nnC++;
		}
		if (playerUp[i]->getName() == LANCE)
		{
			lC++;
			if (playerUp[i]->getPosition() == NULL) nlC++;
		}
		if (playerUp[i]->getName() == SILVER_GENERAL)
		{
			sgC++;
			if (playerUp[i]->getPosition() == NULL) nsgC++;
		}
		if (playerUp[i]->getName() == GOLDEN_GENERAL)
		{
			ggC++;
			if (playerUp[i]->getPosition() == NULL) nggC++;
		}
		if (playerUp[i]->getName() == KING)
		{
			kC++;
			if (playerUp[i]->getPosition() == NULL) nkC++;
		}
	}

	std::cout << "PlayerU:          P: " << pC << "| R: " << rC << "| B: " << bC << "| K: " << nC
		<< "| L: " << lC << "| G_G: " << ggC << "| S_G: " << sgC << "| K: " << kC << std::endl;
	std::cout << "PlayerU Captured: P: " << npC << "| R: " << nrC << "| B: " << nbC << "| K: " << nnC
		<< "| L: " << nlC << "| G_G: " << nggC << "| S_G: " << nsgC << "| K: " << nkC << "\n" << std::endl;


	/*PLAYER BOTTOM*/
	pC = 0, rC = 0, bC = 0, nC = 0, kC = 0, sgC = 0, ggC = 0, lC = 0;
	/*Not inssert pieces*/
	npC = 0, nrC = 0, nbC = 0, nnC = 0, nkC = 0, nsgC = 0, nggC = 0, nlC = 0;

	for (int i = 0; i < playerBottom.size(); i++)
	{
		if (playerBottom[i]->getName() == PAWN)
		{
			pC++;
			if (playerBottom[i]->getPosition() == NULL) npC++;
		}
		if (playerBottom[i]->getName() == ROOK)
		{
			rC++;
			if (playerBottom[i]->getPosition() == NULL) nrC++;
		}
		if (playerBottom[i]->getName() == BISHOP)
		{
			bC++;
			if (playerBottom[i]->getPosition() == NULL) nbC++;
		}
		if (playerBottom[i]->getName() == KNIGHT)
		{
			nC++;
			if (playerBottom[i]->getPosition() == NULL) nnC++;
		}
		if (playerBottom[i]->getName() == LANCE)
		{
			lC++;
			if (playerBottom[i]->getPosition() == NULL) nlC++;
		}
		if (playerBottom[i]->getName() == SILVER_GENERAL)
		{
			sgC++;
			if (playerBottom[i]->getPosition() == NULL) nsgC++;
		}
		if (playerBottom[i]->getName() == GOLDEN_GENERAL)
		{
			ggC++;
			if (playerBottom[i]->getPosition() == NULL) nggC++;
		}
		if (playerBottom[i]->getName() == KING)
		{
			kC++;
			if (playerBottom[i]->getPosition() == NULL) nkC++;
		}
	}

	std::cout << "PlayerB:          P: " << pC << "| R: " << rC << "| B: " << bC << "| K: " << nC
		<< "| L: " << lC << "| G_G: " << ggC << "| S_G: " << sgC << "| K: " << kC << std::endl;
	std::cout << "PlayerB Captured: P: " << npC << "| R: " << nrC << "| B: " << nbC << "| K: " << nnC
		<< "| L: " << nlC << "| G_G: " << nggC << "| S_G: " << nsgC << "| K: " << nkC << std::endl;
}

piece* Board::getPiece(int x, int y)
{
	return board[x + y * 9].currentPiece;
}

Cell* Board::getCell(int x, int y)
{
	return &board[x + y * 9];
}

bool Board::getReInsertPU()
{
	return reInsertPU;
}

bool Board::getReInsertPB()
{
	return reInsertPB;
}

std::vector<piece*>* Board::getPlayerBottom()
{
	return &playerBottom;
}

std::vector<piece*>* Board::getPlayerUp()
{
	return &playerUp;
}

Cell* Board::getBoard()
{
	return board;
}

