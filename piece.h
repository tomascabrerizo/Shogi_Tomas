#pragma once
struct Cell;

//TODO: Change the Players name to:
//PLAYER_TOP and PLAYER_BOTTOM

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
	const char* name;
	virtual bool validPosition(Cell* move, Owner player) = 0;

public:
	/*Constructor and Destructos*/
	piece(Cell* boardPosition, Owner player);
	~piece();
	/*mechanics functions*/
	void move(Cell* move);
	void setPosition(Cell* boardPosition);
	void promote();
	void setCapture();
	Cell* getPosition();
	Owner getPlayer();
	void setPlayer(Owner player);
	const char* getName();
};

