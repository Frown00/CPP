#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class MenuItem
{
protected:
	string s_command;
	string s_name;
	string type;
public:
	
	virtual void run();
	virtual void run(vector<string> arguments);

	virtual ~MenuItem();

	virtual string getName();
	virtual string getCommand();
	virtual string getType();
};

