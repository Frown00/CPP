#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class PrintTable : public Command
{
public:
	PrintTable();
	~PrintTable();
	void runCommand();
	void runCommand(vector<string> arguments);
};

