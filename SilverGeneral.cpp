#include "SilverGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

SilverGeneral::SilverGeneral(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	kanjiBottom = " S^ |";
	kanjiTop = " Sv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting Silver General to the current board position*/
	position->currentPiece = this;
	name = SILVER_GENERAL;
}

SilverGeneral::~SilverGeneral()
{
	position = NULL;
}

void SilverGeneral::promote()
{
	promoted = true;
	player == PLAYER_UP ? position->kanji = "+Sv |" : position->kanji = "+S^ |";
}

bool SilverGeneral::validPosition(Cell* move, Owner player)
{
	if (!promoted)
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
	}
	else /*If the Silver General promote, its moves like gold general*/
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