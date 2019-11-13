#pragma once
#include "piece.h"
class SilverGeneral : public piece
{
private:
	bool validPosition(Cell* move, Owner player);

public:
	/*Constructor and Destructor*/
	SilverGeneral(Cell* boardPosition, Owner player);
	~SilverGeneral();
};

