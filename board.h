#pragma once
#include <iostream>
#include "Cell.h"
#include "piece.h"
#include "king.h"
#include "rook.h"
#include "pawn.h"
#include "bishop.h"
#include "GoldGeneral.h"
#include "SilverGeneral.h"
#include "Knight.h"
#include "Lance.h"

class Board
{
private:
	//shogi board
	Cell board[9 * 9];

	//Array of pointer to players pieces
	piece* player1[20];
	piece* player2[20];

public:
	/*Constructor and destructor*/
	Board();
	~Board();
	piece* getPiece(int x, int y);
	Cell* getCell(int x, int y);
	void render();
};

