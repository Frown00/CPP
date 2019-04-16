#pragma once
#include "./Command.h"
#include "./Tables.h"

extern Tables tables;

class CopyTable : public Command
{
public:
	CopyTable();
	~CopyTable();
	void runCommand();
	void runCommand(vector<string> arguments);
};

