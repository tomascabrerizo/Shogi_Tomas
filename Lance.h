#pragma once
#include "piece.h"

class Lance : public piece
{

private:
	bool validPosition(Cell* move, Owner player);

public:
	/*Constructor and Destructor*/
	Lance(Cell* boardPosition, Owner player, Cell* firstCellofBoard);
	~Lance();

	bool promote();
};

