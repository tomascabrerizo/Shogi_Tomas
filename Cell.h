#pragma once
#include "piece.h"
#include <string>

struct Cell
{
	int x;
	int y;
	std::string kanji;
	piece* currentPiece;
};
