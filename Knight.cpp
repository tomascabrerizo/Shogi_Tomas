#include "Knight.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

Knight::Knight(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and captured in pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Nv |" : position->kanji = " N^ |";
	/*Setting Knight to the current board position*/
	position->currentPiece = this;
}

Knight::~Knight()
{
	position = NULL;
}

void Knight::move(Cell* move)
{
	//TODO: chage Owner if and if else for switch 
	if (player == PLAYER_DOWN)
	{
		if ((position->y == move->y + 2) && ((position->x == move->x - 1)||(position->x == move->x + 1)))
		{
			/*Knight canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Knight Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			player == PLAYER_UP ? position->kanji = " Nv| " : position->kanji = " N^ |";
			position->currentPiece = this;
			std::cout << "Knight Moved" << std::endl;
		}
		else
		{
			std::cout << "Knight cannot move to that cell" << std::endl;
		}
	}
	else if (player == PLAYER_UP)
	{
		if ((position->y == move->y - 2) && ((position->x == move->x - 1) || (position->x == move->x + 1)))
		{
			/*Knight canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Knight Pawn new Position*/
			//TODO: simply render the PLAYER_UP character
			player == PLAYER_UP ? position->kanji = " Nv| " : position->kanji = " N^ |";
			position->currentPiece = this;
			std::cout << "Knight Moved" << std::endl;
		}
		else
		{
			std::cout << "Knight cannot move to that cell" << std::endl;
		}
	}
}

