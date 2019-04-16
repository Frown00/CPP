#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class SetName : public Command
{
public:
	SetName();
	~SetName();
	void runCommand();
	void runCommand(vector<string> arguments);
};

