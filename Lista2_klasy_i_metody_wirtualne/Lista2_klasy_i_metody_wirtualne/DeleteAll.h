#pragma once
#include "./Command.h"

class DeleteAll : public Command
{
public:
	DeleteAll();
	~DeleteAll();
	void runCommand();
};

