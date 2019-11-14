#pragma once
#include "board.h"
#include <iostream>

class Game
{
private:
	bool gameRunning;
	Board shogi;
	int checkedNumber(const char* message);
	std::vector<piece*>* player1;
	std::vector<piece*>* player2;

public:
	/*Constructor and Destructor*/
	Game();
	~Game();

	void update();
	void render();

	bool isRunning();
};

