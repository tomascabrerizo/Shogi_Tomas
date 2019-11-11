#include "SilverGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

SilverGeneral::SilverGeneral(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Sv |" : position->kanji = " S^ |";
	/*Setting Silver General to the current board position*/
	position->currentPiece = this;
}

SilverGeneral::~SilverGeneral()
{
	position = NULL;
}

void SilverGeneral::move(Cell* move)
{
	if (player == PLAYER_DOWN)
	{
		//TODO: try to simplify this code
		if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y - 1) && ((position->x == move->x - 1) || (position->x == move->x + 1))))
		{
			/*Silver General canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Silver General Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			player == PLAYER_UP ? position->kanji = " Sv| " : position->kanji = " S^ |";
			position->currentPiece = this;
			std::cout << "Silver General Moved" << std::endl;
		}
		else
		{
			std::cout << "Silver General cannot move to that cell" << std::endl;
		}
	}
	else if (player == PLAYER_UP)
	{
		//TODO: try to simplify this code
		if (((position->y == (move->y - 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y + 1) && ((position->x == move->x - 1) || (position->x == move->x + 1))))
		{
			/*Silver General canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Silver General Pawn new Position*/
			//TODO: simply render the PLAYER_UP character
			player == PLAYER_UP ? position->kanji = " Sv| " : position->kanji = " S^ |";
			position->currentPiece = this;
			std::cout << "Silver General Moved" << std::endl;
		}
		else
		{
			std::cout << "Silver General cannot move to that cell" << std::endl;
		}
	}
}
