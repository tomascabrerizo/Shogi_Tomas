#include "piece.h"
#include "Cell.h"
#include "board.h"


piece::piece(Cell* boardPosition, Owner player)
{
	/*Set the initial position*/
	position = boardPosition;
	this->player = player;
	captured = false;
	promoted = false;

}

piece::~piece()
{
	position = NULL;
}

void piece::setPosition(Cell* boardPosition)
{
	position = boardPosition;
}

void piece::promote()
{
	promoted = true;
}

void piece::setCapture()
{
	captured = true;
}

Cell* piece::getPosition()
{
	return position;
}

void piece::setPlayer(Owner player)
{
	this->player = player;
}
