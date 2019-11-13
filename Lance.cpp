#include "Lance.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>


Lance::Lance(Cell* boardPosition, Owner player, Cell* fistCellofBoard) : piece(boardPosition, player)
{
	//TODO: initiallize currentPiece promote and captured in pieces
	captured = false;
	promoted = false;
	player == PLAYER_UP ? position->kanji = " Lv |" : position->kanji = " L^ |";
	/*Setting Lance to the current board position*/
	position->currentPiece = this;
	name = "Lance";
	this->fistCellofBoard = fistCellofBoard;
}

Lance::~Lance()
{
	position = NULL;
}

bool Lance::validPosition(Cell* move, Owner player)
{
	if (player == PLAYER_DOWN)
	{
		if ((position->y > move->y) && (position->x == move->x))
		{
			//TODO: make a function to not repeat y PLAYER_UP and PLAYER_DOWN

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
	}
	else if (player == PLAYER_UP)
	{
		if ((position->y < move->y) && (position->x == move->x))
		{
			//TODO: make a function to not repeat y PLAYER_UP and PLAYER_DOWN

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
	}
	return false;
}
