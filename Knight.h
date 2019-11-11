#pragma once
#include "piece.h"

class Knight : public piece
{
public:
	/*Constructor and Destructor*/
	Knight(Cell* boardPosition, Owner player);
	~Knight();
	void move(Cell* move);
};

