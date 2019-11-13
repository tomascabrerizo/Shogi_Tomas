#include "rook.h"
#include "Cell.h"
#include <iostream>

rook::rook(Cell* boardPosition, Owner player, Cell* fistCellofBoard) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and captured in the piece class
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Rv |" : position->kanji = " R^ |";
	/*Setting rook to the current board position*/
	position->currentPiece = this;
	name = "Rook";
	this->fistCellofBoard = fistCellofBoard;
}

rook::~rook()
{
	position = NULL;
}

bool rook::validPosition(Cell* move, Owner player)
{
	/*Checks if the position where the rook have to move is valid*/
	if (((move->x > position->x || move->x < position->x) && move->y == position->y) ||
		((move->y > position->y || move->y < position->y) && move->x == position->x))
	{
		//Save movement Distance
		int distanceX = move->x - position->x;
		int distanceY = move->y - position->y;

		/*subtract one to only check the cells between the movement*/
		distanceX > 0 ? distanceX-- : distanceX;
		distanceX < 0 ? distanceX++ : distanceX;

		distanceY > 0 ? distanceY-- : distanceY;
		distanceY < 0 ? distanceY++ : distanceY;

		while (distanceX != 0 || distanceY != 0)
		{

			if (fistCellofBoard[(position->x + distanceX) + (position->y + distanceY) * 9].currentPiece == NULL)
			{
				//TODO: Simplify this if statements
				//Change the distance to check the next cell
				if (distanceX > 0)
					distanceX--;
				if (distanceY > 0)
					distanceY--;
				if (distanceX < 0)
					distanceX++;
				if (distanceY < 0)
					distanceY++;
			}
			else
			{
				return false;
			}
		}

		return true;
	}
	
	return false;
}