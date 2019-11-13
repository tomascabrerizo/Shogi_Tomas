#pragma once
#include "piece.h"

class Lance : public piece
{

private:
	/*Pointer to first cell of the board to get acces to the whole board*/
	Cell* fistCellofBoard;
	bool validPosition(Cell* move, Owner player);

public:
	/*Constructor and Destructor*/
	Lance(Cell* boardPosition, Owner player, Cell* fistCellofBoard);
	~Lance();
};

