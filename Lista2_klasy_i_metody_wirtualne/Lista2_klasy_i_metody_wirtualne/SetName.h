#pragma once
#include "./Command.h"
class SetName : public Command
{
public:
	SetName();
	~SetName();
	void runCommand();
	void runCommand(vector<string> arguments);
};

