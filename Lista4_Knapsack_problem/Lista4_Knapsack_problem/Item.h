#pragma once
#include <string>
using namespace std;

class Item
{
	string name;
	double value;
	double size;
public:
	Item(const string name, double size, double val);
	~Item();
	string getName();
	double getValue();
	double getSize();
};

