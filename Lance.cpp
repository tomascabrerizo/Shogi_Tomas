#include "Lance.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>


Lance::Lance(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and captured in pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Lv |" : position->kanji = " L^ |";
	/*Setting Lance to the current board position*/
	position->currentPiece = this;
}

Lance::~Lance()
{
	position = NULL;
}

void Lance::move(Cell* move)
{
	//TODO: chage Owner if and if else for switch 
	if (player == PLAYER_DOWN)
	{
		if ((position->y > move->y) && (position->x == move->x))
		{
			/*Lance canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Lance Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			player == PLAYER_UP ? position->kanji = " Lv| " : position->kanji = " L^ |";
			position->currentPiece = this;
			std::cout << "Lance Moved" << std::endl;
		}
		else
		{
			std::cout << "Lance cannot move to that cell" << std::endl;
		}
	}
	else if (player == PLAYER_UP)
	{
		if ((position->y < move->y) && (position->x == move->x))
		{
			/*Lance canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Lance Pawn new Position*/
			//TODO: simply render the PLAYER_UP character
			player == PLAYER_UP ? position->kanji = " Lv| " : position->kanji = " L^ |";
			position->currentPiece = this;
			std::cout << "Lance Moved" << std::endl;
		}
		else
		{
			std::cout << "Lance cannot move to that cell" << std::endl;
		}
	}
}
