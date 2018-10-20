#pragma once
#include "./Command.h"

class DeleteTable : public Command
{
public:
	DeleteTable();
	~DeleteTable();
	void runCommand();
	void runCommand(vector<string> arguments);
};

