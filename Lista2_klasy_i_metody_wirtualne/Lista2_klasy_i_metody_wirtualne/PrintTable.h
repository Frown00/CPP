#pragma once
#include "./Command.h"
class PrintTable : public Command
{
public:
	PrintTable();
	~PrintTable();
	void runCommand();
	void runCommand(vector<string> arguments);
};

