#pragma once
#include "piece.h"

//inheritance from virtual class piece
class king : public piece
{
private:
	bool validPosition(Cell* move, Owner player);
public:
	king(Cell* boardPosition, Owner player);
	~king();
};

