#include "SetValue.h"



SetValue::SetValue()
{
}


SetValue::~SetValue()
{
}

void SetValue::runCommand()
{
	cout << CMD_MUST_HAS_ARGS << endl;
}

void SetValue::runCommand(vector<string> arguments)
{
	int argSize = arguments.size();
	int requireArgSize = 3;
	int index = -1;
	int valIndex = -1;
	int val = NULL;

	if (isNumber(arguments[0]))
		index = stoi(arguments[0]);
	else {
		cout << FIRST_ARG_MUST_BE_NUM << endl;
	}

	if (isNumber(arguments[1])) {
		valIndex = stoi(arguments[1]);
	}
	else {
		cout << SECOND_ARG_MUST_BE_NUM << endl;
	}

	if (isNumber(arguments[2])) {
		val = stoi(arguments[2]);
	}
	else {
		cout << THIRD_ARG_MUST_BE_NUM << endl;
	}

	if (index >= 0 && valIndex >= 0 && val != NULL && argSize == requireArgSize) {

		tables.setValue(index, valIndex, val);
		cout << VALUE_CHANGED << endl;
	}
	else if (argSize > requireArgSize) {
		cout << WRONG_NUM_OF_ARGS << endl;
	}
	else {
		cout << WRONG_CMD << endl;
	}
}
