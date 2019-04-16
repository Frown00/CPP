#include "MenuCommand.h"
#define TYPE "Command"
#define NO_COMMAND "pusta komenda"

MenuCommand::MenuCommand()
{
	command = NULL;
	type = TYPE;
}

MenuCommand::MenuCommand(string name, string cmd, string helpInfo)
{
	s_name = name;
	s_command = cmd;
	s_help = helpInfo;
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
		cout << NO_COMMAND << endl;
	}
}

void MenuCommand::run(vector<string> arguments)
{
	if (command) {
		command->runCommand(arguments);
	}
	else {
		cout << NO_COMMAND << endl;
	}
}

void MenuCommand::assignCommand(Command* cmd)
{
	command = cmd;
}

string MenuCommand::getHelp()
{
	return s_help;
}

