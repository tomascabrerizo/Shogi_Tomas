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

	/**************************************************/
	/*initialized player pieces positions on the board*/
	/**************************************************/
	/*Allocate the pieces on the heap to achive polymorphism*/

	//player1 and player2 kings;
	player1.push_back(new king(&board[4 + 8 * 9], PLAYER_DOWN));
	player2.push_back(new king(&board[4 + 0 * 9], PLAYER_UP));

	//player1 and player2 rook;
	player1.push_back(new rook(&board[7 + 7 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	player2.push_back(new rook(&board[1 + 1 * 9], PLAYER_UP, &board[0 + 0 * 9]));

	//Player1 and player2 pawns
	for (int i = 0; i < 9; i++)
	{
		player1.push_back(new pawn(&board[i + 6 * 9], PLAYER_DOWN));
		player2.push_back(new pawn(&board[i + 2 * 9], PLAYER_UP));
	}

	//Player1 and player2 bishop
	player1.push_back(new bishop(&board[1 + 7 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	player2.push_back(new bishop(&board[7 + 1 * 9], PLAYER_UP, &board[0 + 0 * 9]));

	//Player1 and Player 2 Gold Generlars
	player1.push_back(new GoldGeneral(&board[3 + 8 * 9], PLAYER_DOWN));
	player1.push_back(new GoldGeneral(&board[5 + 8 * 9], PLAYER_DOWN));
	player2.push_back(new GoldGeneral(&board[3 + 0 * 9], PLAYER_UP));
	player2.push_back(new GoldGeneral(&board[5 + 0 * 9], PLAYER_UP));

	//Player1 and Player 2 Silver Generlars
	player1.push_back(new SilverGeneral(&board[2 + 8 * 9], PLAYER_DOWN));
	player1.push_back(new SilverGeneral(&board[6 + 8 * 9], PLAYER_DOWN));
	player2.push_back(new SilverGeneral(&board[2 + 0 * 9], PLAYER_UP));
	player2.push_back(new SilverGeneral(&board[6 + 0 * 9], PLAYER_UP));

	//Player1 and Player2 knights
	player1.push_back(new Knight(&board[1 + 8 * 9], PLAYER_DOWN));
	player1.push_back(new Knight(&board[7 + 8 * 9], PLAYER_DOWN));
	player2.push_back(new Knight(&board[1 + 0 * 9], PLAYER_UP));
	player2.push_back(new Knight(&board[7 + 0 * 9], PLAYER_UP));

	//Player1 and Player2 Lancers
	player1.push_back(new Lance(&board[0 + 8 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	player1.push_back(new Lance(&board[8 + 8 * 9], PLAYER_DOWN, &board[0 + 0 * 9]));
	player2.push_back(new Lance(&board[0 + 0 * 9], PLAYER_UP, &board[0 + 0 * 9]));
	player2.push_back(new Lance(&board[8 + 0 * 9], PLAYER_UP, &board[0 + 0 * 9]));


	reInsertPB = false;
	reInsertPU = false;
}

Board::~Board()
{
	//free the heap before end
	for (piece* tmp : player1)
	{
		delete tmp;
	}
	for (piece* tmp : player2)
	{
		delete tmp;
	}
}

void Board::update()
{
	/*Check for new captured pieces, if one piece is capture change sides*/
	for (int i = 0; i < player1.size(); i++)
	{
		if (player1[i]->isCapture())
		{
			player1[i]->setCapture(false);
			player2.push_back(player1[i]);
			std::cout << "One " << player1[i]->getName() << " change side " << std::endl;
			player1.erase(player1.begin()+i);
		}
	}
	/*Check for new captured pieces, if one piece is capture change sides*/
	for (int i = 0; i < player2.size(); i++)
	{
		if (player2[i]->isCapture())
		{
			player2[i]->setCapture(false);
			player1.push_back(player2[i]);
			std::cout << "One " << player2[i]->getName() << " change side " << std::endl;
			player2.erase(player2.begin() + i);
		}
	}

	/*PLAYER UP*/
	/*pieces conters*/
	int pC = 0, rC = 0, bC = 0, nC = 0, kC = 0, sgC = 0, ggC = 0, lC = 0;

	for (int i = 0; i < player2.size(); i++)
	{
		player2[i]->getName() == PAWN ? pC++ : pC;
		player2[i]->getName() == ROOK ? rC++ : rC;
		player2[i]->getName() == BISHOP ? bC++ : bC;
		player2[i]->getName() == KNIGHT ? nC++ : nC;
		player2[i]->getName() == LANCE ? lC++ : lC;
		player2[i]->getName() == GOLDEN_GENERAL ? ggC++ : ggC;
		player2[i]->getName() == SILVER_GENERAL ? sgC++ : sgC;
		player2[i]->getName() == KING ? kC++ : kC;

		/*Check if there are any pieces outside the board*/
		player2[i]->getPosition() == NULL ? reInsertPU = true : reInsertPU = false;
	}

	std::cout << "PlayerU: Pawns: " << pC << "| Rooks: " << rC << "| Bishops: " << bC << "| Knights: " << nC
		<< "| Lancers: " << lC << "| G_Generals: " << ggC << "| S_Generals: " << sgC << "| King: " << kC << std::endl;

	/*PLAYER BOTTOM*/
	pC = 0, rC = 0, bC = 0, nC = 0, kC = 0, sgC = 0, ggC = 0, lC = 0;

	for (int i = 0; i < player1.size(); i++)
	{
		player1[i]->getName() == PAWN ? pC++ : pC;
		player1[i]->getName() == ROOK ? rC++ : rC;
		player1[i]->getName() == BISHOP ? bC++ : bC;
		player1[i]->getName() == KNIGHT ? nC++ : nC;
		player1[i]->getName() == LANCE ? lC++ : lC;
		player1[i]->getName() == GOLDEN_GENERAL ? ggC++ : ggC;
		player1[i]->getName() == SILVER_GENERAL ? sgC++ : sgC;
		player1[i]->getName() == KING ? kC++ : kC;

		/*Check if there are any pieces outside the board*/
		player1[i]->getPosition() == NULL ? reInsertPB = true : reInsertPB = false;
	}

	std::cout << "PlayerB: Pawns: " << pC << "| Rooks: " << rC << "| Bishops: " << bC << "| Knights: " << nC
		<< "| Lancers: " << lC << "| G_Generals: " << ggC << "| S_Generals: " << sgC << "| King: " << kC << std::endl;

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

std::vector<piece*>* Board::getPlayer1()
{
	return &player1;
}

std::vector<piece*>* Board::getPlayer2()
{
	return &player2;
}

Cell* Board::getBoard()
{
	return board;
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
			else if(y > 1 && x > 0)
			{
				std::cout << board[(x - 1) + (y - 2) * 9].kanji;
			}
		}
		std::cout << "\n";
		if(y == 0 || y == 10)
			std::cout << "--------------------------------------------------\n";
		else
			std::cout << "----|----|----|----|----|----|----|----|----|----|\n";
	}

}