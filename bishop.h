#pragma once
#include "piece.h"

//inheritance from virtual class piece
class bishop : public piece
{
public:
	bishop(Cell* boardPosition, Owner player);
	~bishop();
	void move(Cell* move);
};

