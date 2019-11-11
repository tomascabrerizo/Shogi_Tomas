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
}

bishop::~bishop()
{
	position = NULL;
}

void bishop::move(Cell* move)
{
	if (abs(move->x - position->x) == abs(move->y - position->y))
	{
		/*Bishop canged position, free current position*/
		position->kanji = "    |";
		position->currentPiece = NULL;
		position = move;
		/*Bishop Pawn new Position*/
		player == PLAYER_UP ? position->kanji = " Bv| " : position->kanji = " B^ |";
		position->currentPiece = this;
		std::cout << "Bishop Moved" << std::endl;
	}
	else
	{
		std::cout << "Bishop cannot move to that cell" << std::endl;
	}
}