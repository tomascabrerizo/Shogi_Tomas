#pragma once
#include "piece.h"

//inheritance from virtual class piece
class pawn : public piece
{
public:
	/*Constructor and Destrucor*/
	pawn(Cell* boardPosition, Owner player);
	~pawn();
	void move(Cell* move);
};

