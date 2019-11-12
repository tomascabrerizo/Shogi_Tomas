#pragma once
#include "board.h"
#include <iostream>

class Game
{
private:
	bool gameRunning;
	Board shogi;
	void checkNumber(int& num);

public:
	/*Constructor and Destructor*/
	Game();
	~Game();

	void update();
	void render();

	bool isRunning();
};

