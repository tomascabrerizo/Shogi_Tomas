#pragma once
#include "piece.h"

//inheritance from virtual class piece
class bishop : public piece
{
private:
	bool validPosition(Cell* move, Owner player);

public:
	bishop(Cell* boardPosition, Owner player, Cell* firstCellofBoard);
	~bishop();

	bool promote();
};

