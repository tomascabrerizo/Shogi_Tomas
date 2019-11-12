#include "bishop.h"
#include "Cell.h"
#include <iostream>
#include <math.h>

bishop::bishop(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Bv |" : position->kanji = " B^ |";
	/*Setting bishop to the current board position*/
	position->currentPiece = this;
	name = "Bishop";
}

bishop::~bishop()
{
	position = NULL;
}

bool bishop::validPosition(Cell* move, Owner player)
{
	if (abs(move->x - position->x) == abs(move->y - position->y))
	{
		return true;
	}
	return false;
}
