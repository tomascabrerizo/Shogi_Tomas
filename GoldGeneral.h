#pragma once
#include "piece.h"
class GoldGeneral : public piece
{
private:
	bool validPosition(Cell* move, Owner player);

public:
	/*Constructor and destructor*/
	GoldGeneral(Cell* boardPosition, Owner player, Cell* firstCellofBoard);
	~GoldGeneral();
};

