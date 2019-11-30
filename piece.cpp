#include "piece.h"
#include "Cell.h"
#include "board.h"


piece::piece(Cell* boardPosition, Owner player, Cell* firstCellofBoard)
{
	/*Set the initial position*/
	position = boardPosition;
	this->player = player;
	captured = false;
	promoted = false;
	canPromote = false;
	this->firstCellofBoard = firstCellofBoard;
	lastPieceCaptured = NULL;
}

bool piece::move(Cell* move)
{
	if (validPosition(move, player))
	{
		if (move->currentPiece != NULL && move->currentPiece->getPlayer() == player)
		{
			std::cout << "This cell has your: " << move->currentPiece->getName() << std::endl;
			return false;
		}
		else if (move->currentPiece != NULL && move->currentPiece->getPlayer() != player)
		{
			/*Set last piece captured*/
			lastPieceCaptured = move->currentPiece;
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
			if (player == PLAYER_TOP && position->y >= 6 && canPromote)
			{
				char answer;
				std::cout << "You can promote your: " << name << "enter y to promote it" << std::endl;
				std::cin >> answer;
				if (answer == 'y')
				{
					if (promote())
					{
						std::cout << "You " << name << " was promoted" << std::endl;
					}
				}
			}
			if (player == PLAYER_BOTTOM && position->y <= 2 && canPromote)
			{
				char answer;
				std::cout << "You can promote your: " << name << "enter y to promote it" << std::endl;
				std::cin >> answer;
				if (answer == 'y')
				{
					if (promote())
					{
						std::cout << "You " << name << " was promoted" << std::endl;
					}
				}
			}
			return true;
		}
		else
		{
			/*piece canged position, free current position*/
			lastPieceCaptured = NULL;
			/*Set the kanji in the new position*/
			move->kanji = position->kanji;
			/*Clear the old position kanji*/
			position->kanji = "    |";
			position->currentPiece = NULL;
			position = move;
			/*piece Pawn new Position*/
			//TODO: simply render the PLAYER_DOWN character
			position->currentPiece = this;
			if (player == PLAYER_TOP && position->y >= 6 && canPromote)
			{
				char answer;
				std::cout << "You can promote your: " << name << "enter y to promote it" << std::endl;
				std::cin >> answer;
				if (answer == 'y')
				{
					if (promote())
					{
						std::cout << "You " << name << " was promoted" << std::endl;
					}
				}
			}
			if (player == PLAYER_BOTTOM && position->y <= 2 && canPromote)
			{
				char answer;
				std::cout << "You can promote your: " << name << "enter y to promote it" << std::endl;
				std::cin >> answer;
				if (answer == 'y')
				{
					if (promote())
					{
						std::cout << "You " << name << " was promoted" << std::endl;
					}
				}
			}
			return true;
		}
	}
	else
	{
		std::cout << "The " << name << " cannot move to that cell" << std::endl;
		return false;
	}
	return false;
}

void piece::forceMove(Cell* move)
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
	std::cout << "You cannot move this piece there, you king is in check!" << std::endl;
}

void piece::forceSetPosition(Cell* boardPosition)
{
	position = boardPosition;
	position->currentPiece = this;
}

const char* piece::getKanjiTop()
{
	return kanjiTop;
}

const char* piece::getKanjiBottom()
{
	return kanjiBottom;
}

char piece::getId()
{
	return id;
}

piece* piece::getLastPieceCaptured()
{
	return lastPieceCaptured;
}

piece::~piece()
{
	position = NULL;
}

bool piece::setPosition(Cell* boardPosition)
{
	//Checks if the board position where we want to set the piece is empty
	if (boardPosition->currentPiece == NULL)
	{
		position = boardPosition;
		position->currentPiece = this;
		return true;
	}
	return false;
}


bool piece::insertPiece(Cell* boardPosition)
{
	//Checks if the board position where we want to set the piece is empty
	if (boardPosition->currentPiece == NULL)
	{
		bool validPos = true;
		//Check if in the entire column for other pawns
		if (id == 'p')
		{
			for (int i = 0; i < 9; i++)
			{
				//Check if in the entire column for other pawns
				if (firstCellofBoard[boardPosition->x + i * 9].currentPiece != NULL &&
					firstCellofBoard[boardPosition->x + i * 9].currentPiece->getId() == 'p' &&
					firstCellofBoard[boardPosition->x + i * 9].currentPiece->getPlayer() == player)
					validPos = false;
			}
		}
		//Check if in the pawn or lancer is in ilegal position
		if (id == 'p' || id == 'l')
		{
			if (player == PLAYER_BOTTOM && boardPosition->y == 0)
				validPos = false;
			if (player == PLAYER_TOP && boardPosition->y == 8)
				validPos = false;
		}
		//check is knight is in ilegal position
		if (id == 'n')
		{
			if (player == PLAYER_BOTTOM && boardPosition->y <= 1)
				validPos = false;
			if (player == PLAYER_TOP && boardPosition->y >= 7)
				validPos = false;
		}

		if(validPos)
		{
			position = boardPosition;
			position->currentPiece = this;
			return true;
		}
	}
	return false;
}


bool piece::promote()
{
	std::cout << "this pieces cannot promote" << std::endl;
	return false;
}

void piece::promote(bool value)
{
	promoted = value;
}

void piece::setCapture()
{
	std::cout << "The " << name << " was Captured" << std::endl;
	/*Wen a piece is capture, its change owner*/
	position = NULL;
	/*Set promote to false*/
	promote(false);
	/*Change piece owner*/
	if (this->player == PLAYER_BOTTOM) this->player = PLAYER_TOP;
	else if (this->player == PLAYER_TOP) this->player = PLAYER_BOTTOM;
	/*Set Captured*/
	captured = true;
}

void piece::updateValidCell(Owner player)
{
	validPositions.clear();
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (validPosition(&firstCellofBoard[x + y * 9], player))
			{
				validPositions.push_back(firstCellofBoard[x + y * 9]);
			}
		}
	}
}

std::vector<Cell> piece::validCell(Owner player)
{
	validPositions.clear();
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (validPosition(&firstCellofBoard[x+y*9], player))
			{
				validPositions.push_back(firstCellofBoard[x + y * 9]);
			}
		}
	}
	return validPositions;
}

void piece::setCapture(bool state)
{
	captured = state;
	if (state == false)
	{
		if (this->player == PLAYER_BOTTOM) this->player = PLAYER_TOP;
		else if (this->player == PLAYER_TOP) this->player = PLAYER_BOTTOM;
	}
}

void piece::setCaptureNotChangePlayer(bool state)
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


