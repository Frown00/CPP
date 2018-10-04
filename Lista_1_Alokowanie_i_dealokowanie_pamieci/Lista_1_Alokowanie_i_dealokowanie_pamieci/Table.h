#pragma once
#include <string>
#include <iostream>

using namespace std;

class Table
{
	string name;
	int* dynamicArray;
	int length;

	int* arrayCopy(int* &array, int len);
public:
	Table();
	Table(string name, int arrLen);
	Table(Table &otherTable);
	~Table();

	void setName(string name);
	bool setLength(int length);
	int setValue(int cell, int value);
	int* getValue(int cell);
	void toString();
};

