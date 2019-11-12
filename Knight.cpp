#include "Knight.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

Knight::Knight(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and captured in pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Nv |" : position->kanji = " N^ |";
	/*Setting Knight to the current board position*/
	position->currentPiece = this;
	name = "Knight";
}

Knight::~Knight()
{
	position = NULL;
}

bool Knight::validPosition(Cell* move, Owner player)
{
	if (player == PLAYER_DOWN)
	{
		if ((position->y == move->y + 2) && ((position->x == move->x - 1) || (position->x == move->x + 1)))
		{
			return true;
		}
	}
	else if (player == PLAYER_UP)
	{
		if ((position->y == move->y - 2) && ((position->x == move->x - 1) || (position->x == move->x + 1)))
		{
			return true;
		}
	}
	return false;
}


