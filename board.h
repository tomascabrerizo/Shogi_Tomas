#pragma once
#include <iostream>
#include "Cell.h"
#include "piece.h"
#include "king.h"
#include "rook.h"
#include "pawn.h"
#include "bishop.h"

class Board
{
private:
	Cell board[9 * 9];

	//Array of pointer to players pieces
	piece* player1[20];
	piece* player2[20];

public:
	Board();
	~Board();
	piece* getPiece(int x, int y);
	Cell* getCell(int x, int y);
	void render();
};

