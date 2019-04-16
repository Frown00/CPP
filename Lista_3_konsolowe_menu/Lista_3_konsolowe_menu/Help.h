#pragma once
#include "./Command.h"

class Help : public Command
{
public:
	Help();
	~Help();
	void runCommand();
	void runCommand(vector<string> arguments);
};

