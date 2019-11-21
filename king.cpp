#include "king.h"
#include "Cell.h"
#include <iostream>

king::king(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " K^ |";
	kanjiTop = " Kv |";

	player == PLAYER_TOP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	position->currentPiece = this;
	name = KING;
	id = 'k';
	this->InCheck = false;
}

king::~king()
{
	position = NULL;
}

void king::updateEnemyPosition()
{
	enemiesPositions.clear();
	/*Array with all the enemy valid positions to check with the king positions*/
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (firstCellofBoard[x + y * 9].currentPiece != NULL)
			{
				if (firstCellofBoard[x + y * 9].currentPiece->getPlayer() != player)
				{
					Owner tmpOwner;
					player == PLAYER_BOTTOM ? tmpOwner = PLAYER_TOP : tmpOwner = PLAYER_BOTTOM;
					piece* tmpPiece = firstCellofBoard[x + y * 9].currentPiece;

					for (Cell tmpCell : tmpPiece->validCell(tmpOwner))
					{
						enemiesPositions.push_back(tmpCell);
					}
				}
			}
		}
	}
}


bool king::isInCheck()
{
	updateEnemyPosition();
	for (int i = 0; i < enemiesPositions.size(); i++)
	{
		if (position->x == enemiesPositions[i].x &&
			position->y == enemiesPositions[i].y)
		{
			this->InCheck = true;
			return InCheck;
		}
	}
	this->InCheck = false;
	return InCheck;
}

bool king::validPosition(Cell* move, Owner player)
{
	if (move->currentPiece != NULL)
	{
		if (move->currentPiece->getPlayer() == player)
		{
			return false;
		}
	}
	if ((move->x == position->x + 1 || move->x == position->x - 1 || move->x == position->x) &&
		(move->y == position->y + 1 || move->y == position->y - 1 || move->y == position->y))
	{
		position->currentPiece = NULL;
		updateEnemyPosition();
		bool validPos = true;
		for (int j = 0; j < enemiesPositions.size(); j++)
		{
			if (move->x == enemiesPositions[j].x &&
				move->y == enemiesPositions[j].y)
			{
				validPos = false;
				break;
			}
		}
		position->currentPiece = this;

		return validPos;
		
	}
	return false;
}

bool king::isInCheckMate()
{
	enemiesPositions.clear();
	/*Array with all the enemy valid positions to check with the king positions*/
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if  (firstCellofBoard[x + y * 9].currentPiece != NULL)
			{
				if (firstCellofBoard[x + y * 9].currentPiece->getPlayer() != player)
				{
					Owner tmpOwner;
						player == PLAYER_BOTTOM ? tmpOwner = PLAYER_TOP : tmpOwner = PLAYER_BOTTOM;
						piece* tmpPiece = firstCellofBoard[x + y * 9].currentPiece;
						/*Update all enemies valid position*/
						for (Cell tmpCell : tmpPiece->validCell(tmpOwner))
						{
							enemiesPositions.push_back(tmpCell);
						}
				}
			}
		}
	}

	/*Update the king valid positions with the update enemies valid positions*/
	updateValidCell(player);

	int positionFlagSize = validPositions.size();
	bool* positionsFlag = new bool[positionFlagSize];
	//Set all the flags to false
	memset(positionsFlag, 0, sizeof(bool) * positionFlagSize);
	bool checkMate = true;

	/*Check all this positions with the king positions, if all king positions are in the array return check mate*/
	for (int i = 0; i < positionFlagSize; i++)
	{
		for (int j = 0; j < enemiesPositions.size(); j++)
		{
			if (validPositions[i].x == enemiesPositions[j].x &&
				validPositions[i].y == enemiesPositions[j].y)
			{
				positionsFlag[i] = true;
				break;
			}
			else
			{
				positionsFlag[i] = false;
			}
		}
	}
	for (int i = 0; i < positionFlagSize; i++)
	{
		if (positionsFlag[i] == false)
		{
			checkMate = false;
		}
	}

	delete[] positionsFlag;

	return checkMate;
}




