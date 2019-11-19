#include "Knight.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

Knight::Knight(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " N^ |";
	kanjiTop = " Nv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting Knight to the current board position*/
	position->currentPiece = this;
	name = KNIGHT;
	id = 'n';
	canPromote = true;
}

Knight::~Knight()
{
	position = NULL;
}

bool Knight::promote()
{
	if (player == PLAYER_UP && position->y >= 6)
	{
		promoted = true;
		position->kanji = "+Nv |";
		return true;
	}
	else if (player == PLAYER_DOWN && position->y <= 2)
	{
		promoted = true;
		position->kanji = "+N^ |";
		return true;
	}
	else
	{
		return false;
	}
}

bool Knight::validPosition(Cell* move, Owner player)
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
	}
	else /*If the knight promote, its moves like gold general*/
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


