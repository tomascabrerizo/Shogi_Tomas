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
}

king::~king()
{
	position = NULL;
}

void king::move(Cell* move)
{
	//check if the move input by the player it is posible
	if ((move->x == position->x + 1 || move->x == position->x - 1 || move->x == position->x) &&
		(move->y == position->y + 1 || move->y == position->y - 1 || move->y == position->y))
	{
		/*King canged position, free current position*/
		position->kanji = "    |";
		position->currentPiece = NULL;
		position = move;
		/*Set King new position*/
		player == PLAYER_UP ? position->kanji = " Kv|" : position->kanji = " K^ |";
		position->currentPiece = this;
		std::cout << "King Moved" << std::endl;
	}
	else
	{
		std::cout << "The king cannot move to that cell" << std::endl;
	}
}


