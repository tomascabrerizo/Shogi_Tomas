#include "Lance.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>


Lance::Lance(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and captured in pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Lv |" : position->kanji = " L^ |";
	/*Setting Lance to the current board position*/
	position->currentPiece = this;
	name = "Lance";
}

Lance::~Lance()
{
	position = NULL;
}

bool Lance::validPosition(Cell* move, Owner player)
{
	if (player == PLAYER_DOWN)
	{
		if ((position->y > move->y) && (position->x == move->x))
		{
			return true;
		}
	}
	else if (player == PLAYER_UP)
	{
		if ((position->y < move->y) && (position->x == move->x))
		{
			return true;
		}
	}
	return false;
}
