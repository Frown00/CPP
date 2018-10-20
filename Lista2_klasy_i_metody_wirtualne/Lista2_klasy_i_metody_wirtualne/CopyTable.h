#pragma once
#include "./Command.h"

class CopyTable : public Command
{
public:
	CopyTable();
	~CopyTable();
	void runCommand();
	void runCommand(vector<string> arguments);
};

