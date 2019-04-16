#include "tools.h"

bool isNumber(std::string num)
{
	bool isNum = true;
	for (int i = 0; i < num.length(); i++) {
		if (!isdigit(num[i]) && num[i] != '-') {
			isNum = false;
			i = num.length();
		}
	}
	return isNum;
}