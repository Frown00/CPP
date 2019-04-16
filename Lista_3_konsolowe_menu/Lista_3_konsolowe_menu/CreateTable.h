#pragma once
#include "./Command.h"
#include "./Tables.h"
extern Tables tables;

class CreateTable : public Command
{
public:
	CreateTable();
	~CreateTable();
	void runCommand();
	void runCommand(vector<string> arguments);

};

