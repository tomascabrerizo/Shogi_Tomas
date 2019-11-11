#include <iostream>
#include "board.h"

int main()
{
	std::cout << "|----------------------|" << std::endl;
	std::cout << "|      Tom's Shogi!    |" << std::endl;
	std::cout << "|----------------------|" << std::endl;

	Board testBoard;

	testBoard.render();

	testBoard.getPiece(3, 6)->move(testBoard.getCell(3, 5));

	std::cout << std::endl;
	testBoard.render();
	
	return 0;
}