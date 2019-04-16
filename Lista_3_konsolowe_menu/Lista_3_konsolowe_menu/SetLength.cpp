#include "SetLength.h"



SetLength::SetLength()
{
}


SetLength::~SetLength()
{
}

void SetLength::runCommand()
{
	cout << CMD_MUST_HAS_ARGS << endl;
}

void SetLength::runCommand(vector<string> arguments)
{
	int argSize = arguments.size();
	int requireArgSize = 2;
	int index = -1;
	int len = 0;
	if (isNumber(arguments[1]))
		len = stoi(arguments[1]);
	else {
		cout << FIRST_ARG_MUST_BE_NUM << endl;
	}

	if (isNumber(arguments[0])) {
		index = stoi(arguments[0]);
	}
	else {
		cout << SECOND_ARG_MUST_BE_NUM << endl;
	}

	if (index >= 0 && len > 0 && argSize == requireArgSize) {

		tables.setLength(index, len);
		cout << LENGTH_CHANGED << endl;
	}
	else if (argSize > requireArgSize) {
		cout << WRONG_NUM_OF_ARGS << endl;
	}
	else {
		cout << WRONG_CMD << endl;
	}
}
