#pragma once
#include "MenuItem.h"
#include "Command.h"


class MenuCommand : public MenuItem
{
	Command* command;
	string s_help;

public:
	MenuCommand();
	MenuCommand(string name, string cmd, string helpInfo);
	~MenuCommand();

	void run();
	void run(vector<string> arguments);
	void assignCommand(Command* cmd);
	string getHelp();
	

};

