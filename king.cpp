#include "king.h"
#include "Cell.h"
#include <iostream>

king::king(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	kanjiBottom = " K^ |";
	kanjiTop = " Kv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	position->currentPiece = this;
	name = KING;
}

king::~king()
{
	position = NULL;
}

bool king::validPosition(Cell* move, Owner player)
{
	if ((move->x == position->x + 1 || move->x == position->x - 1 || move->x == position->x) &&
		(move->y == position->y + 1 || move->y == position->y - 1 || move->y == position->y))
	{
		return true;
	}
	return false;
}



