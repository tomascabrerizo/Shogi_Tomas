#include "rook.h"
#include "Cell.h"
#include <iostream>

rook::rook(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Rv |" : position->kanji = " R^ |";
	/*Setting rook to the current board position*/
	position->currentPiece = this;
	name = "Rook";
}

rook::~rook()
{
	position = NULL;
}

bool rook::validPosition(Cell* move, Owner player)
{
	if (((move->x > position->x || move->x < position->x) && move->y == position->y) ||
		((move->y > position->y || move->y < position->y) && move->x == position->x))
	{
		return true;
	}
	
	return false;
}