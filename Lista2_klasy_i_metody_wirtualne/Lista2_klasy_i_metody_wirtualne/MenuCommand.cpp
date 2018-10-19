#include "MenuCommand.h"



MenuCommand::MenuCommand()
{
	command = NULL;
}

MenuCommand::MenuCommand(string name, string cmd)
{
	s_name = name;
	s_command = cmd;
}


MenuCommand::~MenuCommand()
{
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

void MenuCommand::assignCommend(Command* cmd)
{
	command = cmd;
}
