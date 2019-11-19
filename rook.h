#pragma once
#include "piece.h"

//inheritance from virtual class piece
class rook : public piece
{
private:
	bool validPosition(Cell* move, Owner player);

public:
	rook(Cell* boardPosition, Owner player, Cell* firstCellofBoard);
	~rook();
	bool promote();

};

