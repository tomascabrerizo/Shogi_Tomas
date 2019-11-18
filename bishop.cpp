#include "bishop.h"
#include "Cell.h"
#include <iostream>
#include <math.h>

bishop::bishop(Cell* boardPosition, Owner player, Cell* fistCellofBoard) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and cap[tured int pieces
	kanjiBottom = " B^ |";
	kanjiTop = " Bv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting bishop to the current board position*/
	position->currentPiece = this;
	name = BISHOP;
	id = 'b';
	this->fistCellofBoard = fistCellofBoard;
	canPromote = true;
}

bishop::~bishop()
{
	position = NULL;
}

bool bishop::promote()
{
	if (player == PLAYER_UP && position->y >= 6)
	{
		promoted = true;
		position->kanji = "+Bv |";
		return true;
	}
	else if (player == PLAYER_DOWN && position->y <= 2)
	{
		promoted = true;
		position->kanji = "+B^ |";
		return true;
	}
	else
	{
		return false;
	}
}

bool bishop::validPosition(Cell* move, Owner player)
{
	if (!promoted)
	{
		if (abs(move->x - position->x) == abs(move->y - position->y))
		{
			//Save the movement distanse
			int distanceX = move->x - position->x;
			int distanceY = move->y - position->y;

			//Need to add or subtract one to only check the cells between the movement
			distanceX > 0 ? distanceX-- : distanceX;
			distanceX < 0 ? distanceX++ : distanceX;

			distanceY > 0 ? distanceY-- : distanceY;
			distanceY < 0 ? distanceY++ : distanceY;

			while (distanceX != 0 && distanceY != 0)
			{
				//Checking if in the cell between the movement are others pieces
				if (fistCellofBoard[(position->x + distanceX) + (position->y + distanceY) * 9].currentPiece == NULL)
				{
					//TODO: Simplify this if statements
					distanceX > 0 ? distanceX-- : distanceX;
					distanceX < 0 ? distanceX++ : distanceX;

					distanceY > 0 ? distanceY-- : distanceY;
					distanceY < 0 ? distanceY++ : distanceY;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}
	else //if bishop is promote its also has the king moves
	{
		/*King moves*/
		if ((move->x == position->x + 1 || move->x == position->x - 1 || move->x == position->x) &&
			(move->y == position->y + 1 || move->y == position->y - 1 || move->y == position->y))
		{
			return true;
		}

		/*Bishop Moves*/
		if (abs(move->x - position->x) == abs(move->y - position->y))
		{
			//Save the movement distanse
			int distanceX = move->x - position->x;
			int distanceY = move->y - position->y;

			//Need to add or subtract one to only check the cells between the movement

			distanceX > 0 ? distanceX-- : distanceX;
			distanceX < 0 ? distanceX++ : distanceX;

			distanceY > 0 ? distanceY-- : distanceY;
			distanceY < 0 ? distanceY++ : distanceY;

			while (distanceX != 0 && distanceY != 0)
			{
				//Checking if in the cell between the movement are others pieces
				if (fistCellofBoard[(position->x + distanceX) + (position->y + distanceY) * 9].currentPiece == NULL)
				{
					distanceX > 0 ? distanceX-- : distanceX;
					distanceX < 0 ? distanceX++ : distanceX;

					distanceY > 0 ? distanceY-- : distanceY;
					distanceY < 0 ? distanceY++ : distanceY;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
	}

	return false;
}
