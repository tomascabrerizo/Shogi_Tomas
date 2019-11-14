#pragma once
#include "piece.h"

//inheritance from virtual class piece
class bishop : public piece
{
private:
	bool validPosition(Cell* move, Owner player);
	/*Pointer to first cell of the board to get acces to the whole board*/
	Cell* fistCellofBoard;

public:
	bishop(Cell* boardPosition, Owner player, Cell* fistCellofBoard);
	~bishop();

	void promote();
};

