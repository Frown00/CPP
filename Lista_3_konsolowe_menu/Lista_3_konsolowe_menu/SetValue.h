#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;


class SetValue : public Command
{
public:
	SetValue();
	~SetValue();
	void runCommand();
	void runCommand(vector<string> arguments);
};

