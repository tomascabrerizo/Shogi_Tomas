#include "GoldGeneral.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>

GoldGeneral::GoldGeneral(Cell* boardPosition, Owner player) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Gv |" : position->kanji = " G^ |";
	/*Setting Gold General to the current board position*/
	position->currentPiece = this;
}

GoldGeneral::~GoldGeneral()
{
	position = NULL;
}

void GoldGeneral::move(Cell* move)
{
	if (player == PLAYER_DOWN)
	{
		//TODO: try to simplify this code
		if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
			((position->y == move->y - 1) && (position->x == move->x)))
		{
			/*Gold General canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Gold General Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			player == PLAYER_UP ? position->kanji = " Gv| " : position->kanji = " G^ |";
			position->currentPiece = this;
			std::cout << "Gold General Moved" << std::endl;
		}
		else
		{
			std::cout << "Gold General cannot move to that cell" << std::endl;
		}
	}
	else if(player == PLAYER_UP)
	{
		//TODO: try to simplify this code
		if (((position->y == (move->y - 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
			((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
			((position->y == move->y + 1) && (position->x == move->x)))
		{
			/*Gold General canged position, free current position*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*Gold General Pawn new Position*/
			//TODO: simply render the PLAYER_UP character
			player == PLAYER_UP ? position->kanji = " Gv| " : position->kanji = " G^ |";
			position->currentPiece = this;
			std::cout << "Gold General Moved" << std::endl;
		}
		else
		{
			std::cout << "Gold General cannot move to that cell" << std::endl;
		}
	}
	
}
