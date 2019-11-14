#pragma once
#include "piece.h"

class Knight : public piece
{
private:
	bool validPosition(Cell* move, Owner player);
public:
	/*Constructor and Destructor*/
	Knight(Cell* boardPosition, Owner player);
	~Knight();

	void promote();
};

