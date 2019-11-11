#pragma once
#include "piece.h"
class GoldGeneral : public piece
{
public:
	/*Constructor and destructor*/
	GoldGeneral(Cell* boardPosition, Owner player);
	~GoldGeneral();
	void move(Cell* move);
};

