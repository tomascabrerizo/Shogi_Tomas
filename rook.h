#pragma once
#include "piece.h"

//inheritance from virtual class piece
class rook : public piece
{
public:
	rook(Cell* boardPosition, Owner player);
	~rook();
	void move(Cell* move);
};

