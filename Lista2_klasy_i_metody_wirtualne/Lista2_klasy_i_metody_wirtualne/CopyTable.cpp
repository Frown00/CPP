#include "CopyTable.h"



CopyTable::CopyTable()
{
}


CopyTable::~CopyTable()
{
}

void CopyTable::runCommand()
{
	cout << CMD_MUST_HAS_ARGS << endl;
}

void CopyTable::runCommand(vector<string> arguments)
{
	if (isNumber(arguments[0]) && arguments.size() == 1) {
		int index = stoi(arguments[0]);
		int isExist = tables.copyTable(index);
		if (!isExist) {
			cout << TABLE_DOES_NOT_EXIST << endl;
		}
	}
	else if (arguments.size() > 1) {
		cout << WRONG_NUM_OF_ARGS << endl;
	}
	else if (!isNumber(arguments[0])) {
		cout << ARG_MUST_BE_NUM << endl;
	}
	else {
		cout << WRONG_CMD << endl;
	}
}
