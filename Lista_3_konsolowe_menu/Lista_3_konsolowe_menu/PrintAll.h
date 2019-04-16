#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class PrintAll : public Command
{
public:
	PrintAll();
	~PrintAll();
	void runCommand();

};

