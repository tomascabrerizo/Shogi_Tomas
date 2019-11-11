#include "board.h"

Board::Board()
{
	//Initiallize all player pieces pointers to NULL
	for (int i = 0; i < 20; i++)
	{
		player1[i] = NULL;
		player2[i] = NULL;
	}

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
	player1[0] = new king(&board[4 + 8 * 9], PLAYER_DOWN);
	player2[0] = new king(&board[4 + 0 * 9], PLAYER_UP);

	//player1 and player2 rook;
	player1[1] = new rook(&board[7 + 7 * 9], PLAYER_DOWN);
	player2[1] = new rook(&board[1 + 1 * 9], PLAYER_UP);

	//Player1 and player2 pawns
	for (int i = 2; i < 11; i++)
	{
		player1[i] = new pawn(&board[i-2 + 6 * 9], PLAYER_DOWN);
		player2[i] = new pawn(&board[i-2 + 2 * 9], PLAYER_UP);
	}

	//Player1 and player2 bishop
	player1[11] = new bishop(&board[1 + 7 * 9], PLAYER_DOWN);
	player2[11] = new bishop(&board[7 + 1 * 9], PLAYER_UP);

}

Board::~Board()
{
	//free the heap before end
	for (int i = 0; i < 20; i++)
	{
		if (player1[i] != NULL)
		{
			delete player1[i];
		}
		else
		{
			break;
		}

		if (player2[i] != NULL)
		{
			delete player2[i];
		}
		else
		{
			break;
		}
	}
}

piece* Board::getPiece(int x, int y)
{
	return board[x + y * 9].currentPiece;
}

Cell* Board::getCell(int x, int y)
{
	return &board[x + y * 9];
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
