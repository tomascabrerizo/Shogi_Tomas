#include "pawn.h"
#include "Cell.h"
#include <iostream>

pawn::pawn(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Pv |" : position->kanji = " P^ |";
	/*Setting rook to the current board position*/
	position->currentPiece = this;
}

pawn::~pawn()
{
	position = NULL;
}

void pawn::move(Cell* move)
{
	if (player == PLAYER_DOWN)
	{
		if ((position->x == move->x) && (position->y == (move->y + 1)))
		{
			/*Pawn canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Set Pawn new Position*/
			player == PLAYER_UP ? position->kanji = " Pv |" : position->kanji = " P^ |";
			position->currentPiece = this;
			std::cout << "Pawn Moved" << std::endl;
		}
		else
		{
			std::cout << "Pawn cannot move to that cell" << std::endl;
		}
	}
	else if ((player == PLAYER_UP))
	{
		if ((position->x == move->x) && (position->y == (move->y - 1)))
		{
			/*Pawn canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Set Pawn new Position*/
			player == PLAYER_UP ? position->kanji = " Pv |" : position->kanji = " P^ |";
			position->currentPiece = this;
			std::cout << "Pawn Moved" << std::endl;
		}
		else
		{
			std::cout << "Pawn cannot move to that cell" << std::endl;
		}
	}
}
