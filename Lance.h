#pragma once
#include "piece.h"

class Lance : public piece
{
public:
	/*Constructor and Destructor*/
	Lance(Cell* boardPosition, Owner player);
	~Lance();
	void move(Cell* move);
};

