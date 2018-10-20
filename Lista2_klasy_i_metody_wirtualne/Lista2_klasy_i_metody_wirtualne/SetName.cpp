#include "SetName.h"



SetName::SetName()
{
}


SetName::~SetName()
{
}

void SetName::runCommand()
{
	cout << CMD_MUST_HAS_ARGS << endl;
}

void SetName::runCommand(vector<string> arguments)
{
	int argSize = arguments.size();
	int requireArgSize = 2;
	string newName = arguments[1];
	int index = -1;
	if (isNumber(arguments[0]))
		index = stoi(arguments[0]);
	else
		cout << FIRST_ARG_MUST_BE_NUM << endl;

	if (index >= 0 && argSize == requireArgSize) {

		tables.setName(index, newName);
		cout << NAME_CHANGED << endl;
	}
	else if (argSize > requireArgSize) {
		cout << WRONG_NUM_OF_ARGS << endl;
	}
	else {
		cout << WRONG_CMD << endl;
	}
}
