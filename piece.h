#pragma once
struct Cell;
#include <vector>

//TODO: Change the Players name to:
//PLAYER_TOP and PLAYER_BOTTOM

#define PAWN "Pawn"
#define ROOK "Rook"
#define BISHOP "Bishop"
#define KNIGHT "Knight"
#define LANCE "Lance"
#define GOLDEN_GENERAL "Golden General"
#define SILVER_GENERAL "Silver General"
#define KING "King"

enum Owner
{
	PLAYER_TOP,
	PLAYER_BOTTOM
};

class piece
{
protected:
	Cell* firstCellofBoard;
	/*Board position*/
	Cell* position;
	/*piece Owner*/
	Owner player;

	bool captured;
	bool canPromote;
	bool promoted;
	
	/*Kanji character*/
	const char* kanjiTop;
	const char* kanjiBottom;

	const char* name;
	char id;

	piece* lastPieceCaptured;
	/*Vectors of valid positions*/
	std::vector<Cell> validPositions;

public:
	/*Constructor and Destructos*/
	piece(Cell* boardPosition, Owner player, Cell* firstCellofBoard);
	~piece();

	/*mechanics functions*/
	bool move(Cell* move);
	void forceMove(Cell* move);
	void forceSetPosition(Cell* boardPosition);

	/*Getters and Setters*/
	const char* getKanjiTop();
	const char* getKanjiBottom();

	char getId();
	piece* getLastPieceCaptured();

	bool setPosition(Cell* boardPosition);

	virtual bool promote();
	virtual void promote(bool value);
	Cell* getPosition();

	void setCapture();
	void setCapture(bool state);
	bool isCapture();

	Owner getPlayer();
	void setPlayer(Owner player);

	const char* getName();

	virtual bool validPosition(Cell* move, Owner player) = 0;
	void updateValidCell(Owner player);
	std::vector<Cell> validCell(Owner player);
};

