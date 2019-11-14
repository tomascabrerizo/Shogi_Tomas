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
	
	//TODO: change name to player Bottom and Up
	/*Bottom Player*/
	std::vector<piece*> player1;
	/*Top player*/
	std::vector<piece*> player2;

	bool reInsertPU, reInsertPB;

public:
	/*Constructor and destructor*/
	Board();
	~Board();
	piece* getPiece(int x, int y);
	Cell* getCell(int x, int y);
	bool getReInsertPU();
	bool getReInsertPB();

	//Pointers to the players pieces
	std::vector<piece*>* getPlayer1();
	std::vector<piece*>* getPlayer2();

	//Pointer to the board
	Cell* getBoard();

	void render();
	void update();
};

