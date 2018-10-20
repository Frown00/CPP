#pragma once
#include "./Command.h"

class SetValue : public Command
{
public:
	SetValue();
	~SetValue();
	void runCommand();
	void runCommand(vector<string> arguments);
};

