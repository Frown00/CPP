#pragma once
#include "MenuItem.h"
#include "Command.h"


class MenuCommand : public MenuItem
{
	Command* command;
public:

	MenuCommand();
	MenuCommand(string name, string cmd);
	~MenuCommand();

	void run();
	void run(vector<string> arguments);
	void assignCommend(Command* cmd);
};

