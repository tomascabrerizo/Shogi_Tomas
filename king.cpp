#include "king.h"
#include "Cell.h"
#include <iostream>

king::king(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Kv |" : position->kanji = " K^ |";
	position->currentPiece = this;
	name = "King";
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



