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
	int tableLength = 0;
	if (argSize == requireArgSize) {
		string name = arguments[0];
		if (isNumber(arguments[1]))
			tableLength = stoi(arguments[1]);
		else
			cout << ARG_MUST_BE_NUM << endl;

		if (tableLength > 0) {

			tables.createTable(name, tableLength);
			cout << TABLE_CREATED << endl;
		}
		else {
			cout << WRONG_CMD << endl;
		}
	}
	else {
		cout << WRONG_NUM_OF_ARGS << endl;
	}
	
}

