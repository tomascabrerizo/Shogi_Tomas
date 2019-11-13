#pragma once
#include "piece.h"

//inheritance from virtual class piece
class pawn : public piece
{
private:
	bool validPosition(Cell* move, Owner player);

public:
	/*Constructor and Destrucor*/
	pawn(Cell* boardPosition, Owner player);
	~pawn();
};

