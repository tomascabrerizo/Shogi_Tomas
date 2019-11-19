#include "SilverGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

SilverGeneral::SilverGeneral(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " S^ |";
	kanjiTop = " Sv |";

	player == PLAYER_TOP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting Silver General to the current board position*/
	position->currentPiece = this;
	name = SILVER_GENERAL;
	id = 's';
	canPromote = true;
}

SilverGeneral::~SilverGeneral()
{
	position = NULL;
}

bool SilverGeneral::promote()
{
	if (player == PLAYER_TOP && position->y >= 6)
	{
		promoted = true;
		position->kanji = "+Sv |";
		return true;
	}
	else if (player == PLAYER_BOTTOM && position->y <= 2)
	{
		promoted = true;
		position->kanji = "+S^ |";
		return true;
	}
	else
	{
		return false;
	}
}

bool SilverGeneral::validPosition(Cell* move, Owner player)
{
	//if (move->currentPiece != NULL)
	//{
	//	if (move->currentPiece->getPlayer() == player)
	//	{
	//		return false;
	//	}
	//}
	if (!promoted)
	{
		if (player == PLAYER_BOTTOM)
		{
			if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
				((position->y == move->y - 1) && ((position->x == move->x - 1) || (position->x == move->x + 1))))
			{
				return true;
			}
		}
		else if (player == PLAYER_TOP)
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
		if (player == PLAYER_BOTTOM)
		{
			if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
				((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
				((position->y == move->y - 1) && (position->x == move->x)))
			{
				return true;
			}
		}
		else if (player == PLAYER_TOP)
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