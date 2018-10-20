#include "CreateTable.h"


CreateTable::CreateTable()
{
}


CreateTable::~CreateTable()
{
}

void CreateTable::runCommand()
{
	tables.createTable();
	cout << TABLE_CREATED << endl;
}

void CreateTable::runCommand(vector<string> arguments)
{
	int argSize = arguments.size();
	int requireArgSize = 2;
	string name = arguments[0];
	int len = 0;
	if (isNumber(arguments[1]))
		len = stoi(arguments[1]);
	else
		cout << ARG_MUST_BE_NUM << endl;

	if (len > 0 && argSize == requireArgSize) {
		
		tables.createTable(name, len);
		cout << TABLE_CREATED << endl;
	}
	else if (argSize > requireArgSize) {
		cout << WRONG_NUM_OF_ARGS << endl;
	}
	else {
		cout << WRONG_CMD << endl;
	}
}

