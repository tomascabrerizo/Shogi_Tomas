#pragma once
struct Cell;

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
	PLAYER_UP,
	PLAYER_DOWN
};

class piece
{
protected:
	/*Board position*/
	Cell* position;
	/*piece Owner*/
	Owner player;

	bool captured;
	bool promoted;
	
	const char* kanjiTop;
	const char* kanjiBottom;

	const char* name;
	virtual bool validPosition(Cell* move, Owner player) = 0;

public:
	/*Constructor and Destructos*/
	piece(Cell* boardPosition, Owner player);
	~piece();

	/*mechanics functions*/
	void move(Cell* move);

	/*Getters and Setters*/
	const char* getKanjiTop();
	const char* getKanjiBottom();

	void setPosition(Cell* boardPosition);

	virtual void promote();
	Cell* getPosition();

	void setCapture();
	void setCapture(bool state);
	bool isCapture();

	Owner getPlayer();
	void setPlayer(Owner player);

	const char* getName();
};

