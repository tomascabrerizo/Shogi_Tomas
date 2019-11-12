#include "SilverGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

SilverGeneral::SilverGeneral(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Sv |" : position->kanji = " S^ |";
	/*Setting Silver General to the current board position*/
	position->currentPiece = this;
	name = "Silver General";
}

SilverGeneral::~SilverGeneral()
{
	position = NULL;
}

bool SilverGeneral::validPosition(Cell* move, Owner player)
{
	if (player == PLAYER_DOWN)
	{
		if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y - 1) && ((position->x == move->x - 1) || (position->x == move->x + 1))))
		{
			return true;
		}
	}
	else if (player == PLAYER_UP)
	{
		if (((position->y == (move->y - 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y + 1) && ((position->x == move->x - 1) || (position->x == move->x + 1))))
		{
			return true;
		}
	}
	return false;
}