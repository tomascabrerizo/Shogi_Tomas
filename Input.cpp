#include "Input.h"

Input::Input()
{
	/*Initiallize all values to error*/
	xSource = -1;
	ySource = -1;
	xDest = -1;
	yDest = -1;
	pieceType = 'E';
	succes = false;
	commandType = ERROR;
}

Input::~Input()
{
}

bool Input::checkForCommand()
{
	/*Command name size*/
	char* name = new char[10];
	int nameSize = 0;

	nameSize = 0;
	std::cout << "Command: ";
	std::cin.clear();
	std::cin >> command;
	/*Get the command name*/
	for (int i = 0; i < 10; i++)
	{
		if (i <= command.size())
		{
			if (command[i] == '(')
			{
				break;
			}
			else
			{
				name[i] = command[i];
				nameSize++;
			}
		}
	}
	commandName.resize(nameSize);
	for (int i = 0; i < nameSize; i++)
	{
		commandName[i] = name[i];
	}
	//Free the temp pointer
	delete[] name;
	/*In c++ switch statements is only for int, have to use if else*/
	if (commandName == "move")
	{
		if (command.size() == 10 &&
			(command[nameSize + 1] - 48 >= 0 && command[nameSize + 1] - 48 <= 8) &&
			(command[nameSize + 2] - 48 >= 0 && command[nameSize + 2] - 48 <= 8) &&
			(command[nameSize + 3] - 48 >= 0 && command[nameSize + 3] - 48 <= 8) &&
			(command[nameSize + 4] - 48 >= 0 && command[nameSize + 4] - 48 <= 8) &&
			(command[nameSize + 5] == ')'))
		{
			commandType = MOVE;
			xSource = command[nameSize + 1] - 48;
			ySource = command[nameSize + 2] - 48;
			xDest = command[nameSize + 3] - 48;
			yDest = command[nameSize + 4] - 48;
			return true;
		}
	}
	else if (commandName == "promote")
	{
		if (command.size() == 11 &&
			(command[nameSize + 1] - 48 >= 0 && command[nameSize + 1] - 48 <= 8) &&
			(command[nameSize + 2] - 48 >= 0 && command[nameSize + 2] - 48 <= 8) &&
			(command[nameSize + 3] == ')'))
		{
			commandType = PROMOTE;
			xSource = command[nameSize + 1] - 48;
			ySource = command[nameSize + 2] - 48;
			return true;
		}
	}
	else if (commandName == "insert")
	{
		if (command.size() == 11 &&
			(command[nameSize + 1] == 'p' || command[nameSize + 1] == 'b' ||
				command[nameSize + 1] == 'r' || command[nameSize + 1] == 'n' ||
				command[nameSize + 1] == 'l' || command[nameSize + 1] == 's' ||
				command[nameSize + 1] == 'g') &&
				(command[nameSize + 2] - 48 >= 0 && command[nameSize + 2] - 48 <= 8) &&
			(command[nameSize + 3] - 48 >= 0 && command[nameSize + 3] - 48 <= 8) &&
			(command[nameSize + 4] == ')'))
		{
			commandType = INSERT;
			pieceType = command[nameSize + 1];
			xSource = command[nameSize + 2] - 48;
			ySource = command[nameSize + 3] - 48;
			return true;
		}
	}
	else if (commandName == "end")
	{
		if (command.size() == 5 &&
			(command[nameSize + 1] == ')'))
		{
			commandType = END;
			return true;
		}
	}

	std::cout << "Command not found" << std::endl;
	return false;
}

std::string Input::getCommanName()
{
	return commandName;
}

char Input::getPieceType()
{
	return pieceType;
}

int Input::getXSource()
{
	return xSource;
}

int Input::getYSource()
{
	return ySource;
}

int Input::getXDest()
{
	return xDest;
}

int Input::getYDest()
{
	return yDest;
}

CommandType Input::getCommandType()
{
	return commandType;
}
