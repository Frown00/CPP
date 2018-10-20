#pragma once
#include <vector>
#include "Table.h"

using namespace std;

class Tables
{
	vector<Table*> tables;

public:
	Tables();
	~Tables();

	void createTable();
	void createTable(string name, int len);
	bool setName(int tableIndex, string newName);
	bool setLength(int tableIndex, int len);
	int setValue(int tableIndex, int valueIndex, int value);
	bool copyTable(int tableIndex);
	bool deleteTable(int tableIndex);
	void deleteAllTables();

	bool printTable(int tableIndex);
	void printAll();

};

