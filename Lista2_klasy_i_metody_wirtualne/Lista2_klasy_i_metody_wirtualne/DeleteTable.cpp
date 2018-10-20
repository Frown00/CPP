#include "DeleteTable.h"



DeleteTable::DeleteTable()
{
}


DeleteTable::~DeleteTable()
{
}

void DeleteTable::runCommand()
{
	cout << CMD_MUST_HAS_ARGS << endl;
}

void DeleteTable::runCommand(vector<string> arguments)
{
	if (isNumber(arguments[0]) && arguments.size() == 1) {
		int index = stoi(arguments[0]);
		int isExist = tables.deleteTable(index);
		if (!isExist) {
			cout << TABLE_DOES_NOT_EXIST << endl;
		}
		else {
			cout << TABLE_DELETED << endl;
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
