#pragma once
#include <string>
#include <iostream>

using namespace std;

class MenuItem
{
protected:
	string s_command;
	string s_name;
public:
	
	virtual void run();
	//virtual ~MenuItem();

	virtual string getName();
	virtual string getCommand();
};

