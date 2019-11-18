#include "Lance.h"
#include "Cell.h" /*in piece.h is only define*/
#include <iostream>


Lance::Lance(Cell* boardPosition, Owner player, Cell* fistCellofBoard) : piece(boardPosition, player)
{
	kanjiBottom = " L^ |";
	kanjiTop = " Lv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting Lance to the current board position*/
	position->currentPiece = this;
	name = LANCE;
	id = 'l';
	this->fistCellofBoard = fistCellofBoard;
	canPromote = true;
}

Lance::~Lance()
{
	position = NULL;
}

bool Lance::promote()
{
	if (player == PLAYER_UP && position->y >= 6)
	{
		promoted = true;
		position->kanji = "+Lv |";
		return true;
	}
	else if (player == PLAYER_DOWN && position->y <= 2)
	{
		promoted = true;
		position->kanji = "+L^ |";
		return true;
	}
	else
	{
		return false;
	}
}

bool Lance::validPosition(Cell* move, Owner player)
{
	if (!promoted)
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
	}
	else /*If the lance promote, its moves like gold general*/
	{
		if (player == PLAYER_DOWN)
		{
			if (((position->y == (move->y + 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
				((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
				((position->y == move->y - 1) && (position->x == move->x)))
			{
				return true;
			}
		}
		else if (player == PLAYER_UP)
		{
			if (((position->y == (move->y - 1)) && (position->x >= (move->x - 1) && position->x <= move->x + 1)) ||
				((position->y == move->y) && ((position->x == move->x - 1) || (position->x == move->x + 1))) ||
				((position->y == move->y + 1) && (position->x == move->x)))
			{
				return true;
			}
		}
	}
	return false;
}
