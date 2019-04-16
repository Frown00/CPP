#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class DeleteTable : public Command
{
public:
	DeleteTable();
	~DeleteTable();
	void runCommand();
	void runCommand(vector<string> arguments);
};

