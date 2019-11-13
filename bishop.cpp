#include "bishop.h"
#include "Cell.h"
#include <iostream>
#include <math.h>

bishop::bishop(Cell* boardPosition, Owner player, Cell* fistCellofBoard) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Bv |" : position->kanji = " B^ |";
	/*Setting bishop to the current board position*/
	position->currentPiece = this;
	name = "Bishop";
	this->fistCellofBoard = fistCellofBoard;
}

bishop::~bishop()
{
	position = NULL;
}

bool bishop::validPosition(Cell* move, Owner player)
{
	if (abs(move->x - position->x) == abs(move->y - position->y))
	{
		//Save the movement distanse
		int distanceX = move->x - position->x;
		int distanceY = move->y - position->y;

		//Need to add or subtract one to only check the cells between the movement
		//TODO: Simplify this if statements
		if (distanceX > 0)
			distanceX--;
		else
			distanceX++;

		if (distanceY > 0)
			distanceY--;
		else
			distanceY++;
		
		while (distanceX != 0 && distanceY !=0)
		{
			//Checking if in the cell between the movement are others pieces
			if (fistCellofBoard[(position->x + distanceX) + (position->y + distanceY) * 9].currentPiece == NULL)
			{
				//TODO: Simplify this if statements
				if(distanceX > 0)
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
