#pragma once
#include "./Command.h"
class SetLength : public Command
{
public:
	SetLength();
	~SetLength();
	void runCommand();
	void runCommand(vector<string> arguments);
};

