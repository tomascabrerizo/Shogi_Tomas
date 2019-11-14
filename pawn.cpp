#include "pawn.h"
#include "Cell.h"
#include <iostream>

pawn::pawn(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	kanjiBottom = " P^ |";
	kanjiTop = " Pv |";
	
	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;

	/*Setting rook to the current board position*/
	position->currentPiece = this;
	name = PAWN;
}

pawn::~pawn()
{
	position = NULL;
}

void pawn::promote()
{
	promoted = true;
	player == PLAYER_UP ? position->kanji = "+Pv |" : position->kanji = "+P^ |";
}

bool pawn::validPosition(Cell* move, Owner player)
{
	if (!promoted)
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
	}
	else /*If the pawn promote, its moves like gold general*/
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
	}

	return false;
}
