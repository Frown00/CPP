#pragma once
#include <iostream>
#include <vector>
#include "Tables.h"

using namespace std;


class Menu
{
	vector<string> splitString(string cmd, char delimiter);

	enum commandName {
		CREATE,
		DELETE,
		DELETE_ALL,
		COPY,
		PRINT,
		PRINT_ALL,
		SET_NAME,
		SET_VALUE,
		SET_LENGTH,
		HELP,
		CLEAR,
		EXIT,
		WRONG_CMD
	};

	commandName decodeCmd(string const &inString) {
		if (inString == "create table") return CREATE;
		else if (inString == "set name") return SET_NAME;
		else if (inString == "set value") return SET_VALUE;
		else if (inString == "set length") return SET_LENGTH;
		else if (inString == "copy table") return COPY;
		else if (inString == "print table") return PRINT;
		else if (inString == "print all") return PRINT_ALL;
		else if (inString == "delete table") return DELETE;
		else if (inString == "delete all") return DELETE_ALL;
		else if (inString == "help") return HELP;
		else if (inString == "clear") return CLEAR;
		else if (inString == "exit") return EXIT;
		else return WRONG_CMD;
	};

	bool isNumber(string num);
public:
	
	Menu();
	~Menu();

	void start(Tables*& tabs);
};

