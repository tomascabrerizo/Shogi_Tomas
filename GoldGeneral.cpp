#include "GoldGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

GoldGeneral::GoldGeneral(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Gv |" : position->kanji = " G^ |";
	/*Setting Gold General to the current board position*/
	position->currentPiece = this;
	name = "Golden General";
}

GoldGeneral::~GoldGeneral()
{
	position = NULL;
}

bool GoldGeneral::validPosition(Cell* move, Owner player)
{
	if (player == PLAYER_DOWN)
	{
		if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
			((position->y == move->y - 1) && (position->x == move->x)))
		{
			return true;
		}
	}
	else if (player == PLAYER_UP)
	{
		if (((position->y == (move->y - 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
			((position->y == move->y + 1) && (position->x == move->x)))
		{
			return true;
		}
	}
	return false;
}

