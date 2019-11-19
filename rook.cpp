#include "rook.h"
#include "Cell.h"
#include <iostream>

rook::rook(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " R^ |";
	kanjiTop = " Rv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	/*Setting rook to the current board position*/
	position->currentPiece = this;
	name = ROOK;
	id = 'r';
	canPromote = true;
}

rook::~rook()
{
	position = NULL;
}

bool rook::promote()
{
	if (player == PLAYER_UP && position->y >= 6)
	{
		promoted = true;
		position->kanji = "+Rv |";
		return true;
	}
	else if (player == PLAYER_DOWN && position->y <= 2)
	{
		promoted = true;
		position->kanji = "+R^ |";
		return true;
	}
	else
	{
		return false;
	}
}

bool rook::validPosition(Cell* move, Owner player)
{
	//if (move->currentPiece != NULL)
	//{
	//	if (move->currentPiece->getPlayer() == player)
	//	{
	//		return false;
	//	}
	//}
	if (!promoted)
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

				if (firstCellofBoard[(position->x + distanceX) + (position->y + distanceY) * 9].currentPiece == NULL)
				{
					//Change the distance to check the next cell
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
	else //if rook is promote its also has the king moves
	{
		/*King moves*/
		if ((move->x == position->x + 1 || move->x == position->x - 1 || move->x == position->x) &&
			(move->y == position->y + 1 || move->y == position->y - 1 || move->y == position->y))
		{
			return true;
		}

		/*Rook moves*/
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

				if (firstCellofBoard[(position->x + distanceX) + (position->y + distanceY) * 9].currentPiece == NULL)
				{
					//Change the distance to check the next cell
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