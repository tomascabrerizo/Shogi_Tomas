#include "GoldGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

GoldGeneral::GoldGeneral(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " G^ |";
	kanjiTop = " Gv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting Gold General to the current board position*/
	position->currentPiece = this;
	name = GOLDEN_GENERAL;
	id = 'g';
}

GoldGeneral::~GoldGeneral()
{
	position = NULL;
}

bool GoldGeneral::validPosition(Cell* move, Owner player)
{
	//if (move->currentPiece != NULL)
	//{
	//	if (move->currentPiece->getPlayer() == player)
	//	{
	//		return false;
	//	}
	//}
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

