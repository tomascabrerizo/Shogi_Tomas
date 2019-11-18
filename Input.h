#pragma once
#include <iostream>

enum CommandType
{
	MOVE,
	INSERT,
	PROMOTE,
	RESET,
	END,
	ERROR
};

class Input
{
private:
	std::string command;
	std::string commandName;
	CommandType commandType;
	int xSource, ySource, xDest, yDest;
	char pieceType;
	bool succes;

public:
	Input();
	~Input();

	bool checkForCommand();

	std::string getCommanName();
	char getPieceType();

	int getXSource();
	int getYSource();
	int getXDest();
	int getYDest();
	CommandType getCommandType();
};

