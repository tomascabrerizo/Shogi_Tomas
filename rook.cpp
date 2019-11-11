#include "rook.h"
#include "Cell.h"
#include <iostream>

rook::rook(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Rv |" : position->kanji = " R^ |";
	/*Setting rook to the current board position*/
	position->currentPiece = this;
}

rook::~rook()
{
	position = NULL;
}

void rook::move(Cell* move)
{
	if (((move->x > position->x || move->x < position->x) && move->y == position->y) ||
		((move->y > position->y || move->y < position->y) && move->x == position->x))
	{
		/*Rook canged position, free current position*/
		position->kanji = "    |";
		position->currentPiece = NULL;
		position = move;
		/*Set Rook new Position*/
		player == PLAYER_UP ? position->kanji = " Rv |" : position->kanji = " R^ |";
		position->currentPiece = this;
		std::cout << "Rook Moved" << std::endl;
	}
	else
	{
		std::cout << "Rook cannot move to that cell" << std::endl;
	}
}
