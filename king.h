#pragma once
#include "piece.h"

//inheritance from virtual class piece
class king : public piece
{
private:
	bool validPosition(Cell* move, Owner player);
	std::vector<Cell>enemiesPositions;
	bool InCheck;

public:
	king(Cell* boardPosition, Owner player, Cell* fistCellofBoard);
	~king();
	void updateEnemyPosition();
	bool isInCheck();
	bool isInCheckMate();
};

