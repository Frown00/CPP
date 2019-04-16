#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class DeleteAll : public Command
{
public:
	DeleteAll();
	~DeleteAll();
	void runCommand();
};

