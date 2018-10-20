#pragma once
#include "./Command.h"
class CreateTable : public Command
{
public:
	CreateTable();
	~CreateTable();
	void runCommand();
	void runCommand(vector<string> arguments);

};

