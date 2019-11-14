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

void piece::move(Cell* move)
{
	bool test = validPosition(move, player);
	if (validPosition(move, player))
	{
		if (move->currentPiece != NULL && move->currentPiece->getPlayer() == player)
		{
			std::cout << "This cell has your: " << move->currentPiece->getName() << std::endl;
		}
		else if (move->currentPiece != NULL && move->currentPiece->getPlayer() != player)
		{
			/*piece canged position, free current position*/
			/*land in enemy piece, capture it*/
			move->currentPiece->setCapture();
			/*Set the kanji in the new position*/
			move->kanji = position->kanji;
			/*Clear the old position kanji*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*pieces Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			position->currentPiece = this;
			std::cout << name << " Moved" << std::endl;
		}
		else
		{
			/*piece canged position, free current position*/
			/*Set the kanji in the new position*/
			move->kanji = position->kanji;
			/*Clear the old position kanji*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*piece Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			position->currentPiece = this;
			std::cout << name << " Moved" << std::endl;
		}
	}
	else
	{
		std::cout << "The " << name << " cannot move to that cell" << std::endl;
	}
}

const char* piece::getKanjiTop()
{
	return kanjiTop;
}

const char* piece::getKanjiBottom()
{
	return kanjiBottom;
}

piece::~piece()
{
	position = NULL;
}

void piece::setPosition(Cell* boardPosition)
{
	position = boardPosition;
	position->currentPiece = this;
}

void piece::promote()
{
	promoted = true;
}

void piece::setCapture()
{
	std::cout << "The " << name << " was Captured" << std::endl;
	/*Wen a piece is capture, its change owner*/
	position = NULL;
	/*Change piece owner*/
	if (this->player == PLAYER_DOWN) this->player = PLAYER_UP;
	else if (this->player == PLAYER_UP) this->player = PLAYER_DOWN;
	/*Set Captured*/
	captured = true;
}

void piece::setCapture(bool state)
{
	captured = state;
}

bool piece::isCapture()
{
	return captured;
}

Cell* piece::getPosition()
{
	return position;
}

Owner piece::getPlayer()
{
	return player;
}

void piece::setPlayer(Owner player)
{
	this->player = player;
}

const char* piece::getName()
{
	return name;
}
