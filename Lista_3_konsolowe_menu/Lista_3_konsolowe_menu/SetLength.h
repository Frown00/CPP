#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class SetLength : public Command
{
public:
	SetLength();
	~SetLength();
	void runCommand();
	void runCommand(vector<string> arguments);
};

