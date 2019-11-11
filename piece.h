#pragma once
struct Cell;

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

public:
	/*Constructor and Destructos*/
	piece(Cell* boardPosition, Owner player);
	~piece();
	/*mechanics functions*/
	virtual void move(Cell* move) = 0;
	void setPosition(Cell* boardPosition);
	void promote();
	void setCapture();
	Cell* getPosition();
	void setPlayer(Owner player);
};

