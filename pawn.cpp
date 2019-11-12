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
	name = "Pawn";
}

pawn::~pawn()
{
	position = NULL;
}

bool pawn::validPosition(Cell* move, Owner player)
{
	if (player == PLAYER_DOWN)
	{
		if ((position->x == move->x) && (position->y == (move->y + 1)))
		{
			bool test = ((position->x == move->x) && (position->y == (move->y + 1)));
			return true;
		}
	}
	else if ((player == PLAYER_UP))
	{
		if ((position->x == move->x) && (position->y == (move->y - 1)))
		{
			return true;
		}
	}
	return false;
}