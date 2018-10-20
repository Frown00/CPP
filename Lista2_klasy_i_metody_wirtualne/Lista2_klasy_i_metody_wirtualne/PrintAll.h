#pragma once
#include "./Command.h"

class PrintAll : public Command
{
public:
	PrintAll();
	~PrintAll();
	void runCommand();

};

