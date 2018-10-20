#include "MenuCommand.h"
#define TYPE "MenuCommand"


MenuCommand::MenuCommand()
{
	command = NULL;
	type = TYPE;
}

MenuCommand::MenuCommand(string name, string cmd)
{
	s_name = name;
	s_command = cmd;
	type = TYPE;
}


MenuCommand::~MenuCommand()
{
	delete command;
}

void MenuCommand::run()
{
	if (command) {
		command->runCommand();
	}
	else {
		cout << "pusta komenda" << endl;
	}
}

void MenuCommand::run(vector<string> arguments)
{
	if (command) {
		command->runCommand(arguments);
	}
	else {
		cout << "pusta komenda" << endl;
	}
}

void MenuCommand::assignCommend(Command* cmd)
{
	command = cmd;
}
