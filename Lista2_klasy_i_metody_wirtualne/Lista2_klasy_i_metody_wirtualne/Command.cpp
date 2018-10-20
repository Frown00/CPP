#include "Command.h"

void Command::runCommand()
{
	cout << "Komenda domyslna" << endl;
}

void Command::runCommand(vector<string> arguments)
{
	cout << "Komenda domyslna" << endl;
}

Command::~Command()
{
}
