#pragma once
#include "piece.h"

//inheritance from virtual class piece
class rook : public piece
{
private:
	/*Pointer to first cell of the board to get acces to the whole board*/
	Cell* fistCellofBoard;
	bool validPosition(Cell* move, Owner player);

public:
	rook(Cell* boardPosition, Owner player, Cell* fistCellofBoard);
	~rook();
	void promote();

};

