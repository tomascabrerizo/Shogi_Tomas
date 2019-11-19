#pragma once
#include <iostream>
#include <vector>
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
	
	/*Bottom Player*/
	std::vector<piece*> playerBottom;
	/*Top player*/
	std::vector<piece*> playerUp;

	bool reInsertPU, reInsertPB;

public:
	/*Constructor and destructor*/
	Board();
	~Board();

	/*Initiallize the board*/
	void initBoard();

	void render();
	bool update();

	piece* getPiece(int x, int y);
	Cell* getCell(int x, int y);
	bool getReInsertPU();
	bool getReInsertPB();

	//Pointers to the players pieces
	std::vector<piece*>* getPlayerBottom();
	std::vector<piece*>* getPlayerUp();

	//Pointer to the board
	Cell* getBoard();
};

