#pragma once
#include "piece.h"

//inheritance from virtual class piece
class king : public piece
{
public:
	king(Cell* boardPosition, Owner player);
	~king();
	void move(Cell* move);
};

