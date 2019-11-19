#include "pawn.h"
#include "Cell.h"
#include <iostream>

pawn::pawn(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " P^ |";
	kanjiTop = " Pv |";
	
	player == PLAYER_TOP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;

	/*Setting rook to the current board position*/
	position->currentPiece = this;
	name = PAWN;
	id = 'p';
	canPromote = true;
}

pawn::~pawn()
{
	position = NULL;
}

bool pawn::promote()
{
	if (player == PLAYER_TOP && position->y >= 6)
	{
		promoted = true;
		position->kanji = "+Pv |";
		return true;
	}
	else if (player == PLAYER_BOTTOM && position->y <= 2)
	{
		promoted = true;
		position->kanji = "+P^ |";
		return true;
	}
	else
	{
		return false;
	}
}

bool pawn::validPosition(Cell* move, Owner player)
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
			if ((position->x == move->x) && (position->y == (move->y + 1)))
			{
				bool test = ((position->x == move->x) && (position->y == (move->y + 1)));
				return true;
			}
		}
		else if ((player == PLAYER_TOP))
		{
			if ((position->x == move->x) && (position->y == (move->y - 1)))
			{
				return true;
			}
		}
	}
	else /*If the pawn promote, its moves like gold general*/
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
