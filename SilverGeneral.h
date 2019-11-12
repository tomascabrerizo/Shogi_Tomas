#pragma once
#include "piece.h"
class SilverGeneral : public piece
{
public:
	/*Constructor and Destructor*/
	SilverGeneral(Cell* boardPosition, Owner player);
	~SilverGeneral();
	bool validPosition(Cell* move, Owner player);

};

