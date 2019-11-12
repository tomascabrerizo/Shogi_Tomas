#pragma once
#include "piece.h"

//inheritance from virtual class piece
class king : public piece
{
public:
	king(Cell* boardPosition, Owner player);
	~king();
	bool validPosition(Cell* move, Owner player);
};

