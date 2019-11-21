#pragma once
#include "board.h"
#include "Input.h"
#include <iostream>

class Game
{
private:

	Input gameInput;
	bool gameRunning;
	Board shogi;
	int checkedNumber(const char* message);
	Owner playerTurn;
	bool playerTopWins, playerBottomWins;

	king* kingTop;
	king* kingBottom;

public:
	/*Constructor and Destructor*/
	Game();
	~Game();

	void update();
	void render();

	bool isRunning();
};

