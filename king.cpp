#include "king.h"
#include "Cell.h"
#include <iostream>

king::king(Cell* boardPosition, Owner player, Cell* firstCellofBoard) : piece(boardPosition, player, firstCellofBoard)
{
	kanjiBottom = " K^ |";
	kanjiTop = " Kv |";

	player == PLAYER_UP ? position->kanji = kanjiTop : position->kanji = kanjiBottom;
	position->currentPiece = this;
	name = KING;
	id = 'k';
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
					player == PLAYER_DOWN ? tmpOwner = PLAYER_UP : tmpOwner = PLAYER_DOWN;
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

		bool validPos = true;
		for (int j = 0; j < enemiesPositions.size(); j++)
		{
			if (move->x == enemiesPositions[j].x &&
				move->y == enemiesPositions[j].y)
			{
				validPos = false;
				std::cout << "The King cannot check him self!" << std::endl;
				break;
			}
		}

		return validPos;
		
	}
	return false;
}

bool king::isInCheckMate()
{
	validCell(player);
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
						player == PLAYER_DOWN ? tmpOwner = PLAYER_UP : tmpOwner = PLAYER_DOWN;
						piece* tmpPiece = firstCellofBoard[x + y * 9].currentPiece;

						for (Cell tmpCell : tmpPiece->validCell(tmpOwner))
						{
							enemiesPositions.push_back(tmpCell);
						}
				}
			}
		}
	}
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




