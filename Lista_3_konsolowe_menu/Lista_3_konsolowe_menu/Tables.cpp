#include "Tables.h"

Tables tables;

Tables::Tables()
{
}


Tables::~Tables()
{
	for (int i = 0; i < tables.size(); i++) {
		delete tables[i];
	}
}

void Tables::createTable()
{
	Table* table = new Table();
	this->tables.push_back(table);
}

void Tables::createTable(string name, int len)
{
	Table* table = new Table(name, len);
	this->tables.push_back(table);
}

bool Tables::setName(int tableIndex, string newName)
{
	bool isExist = true;
	if (tables.size() > tableIndex) {
		tables[tableIndex]->setName(newName);
	}
	else {
		isExist = false;
	}

	return isExist;
}

bool Tables::setLength(int tableIndex, int len)
{
	bool isExist = true;
	if (tables.size() > tableIndex) {
		tables[tableIndex]->setLength(len);
	}
	else {
		isExist = false;
	}

	return isExist;
}

int Tables::setValue(int tableIndex, int valueIndex, int value)
{
	int result = 0;
	if (tables.size() > tableIndex) {
		result = tables[tableIndex]->setValue(valueIndex, value);
	}
	else {
		result = -3;
	}

	return result;
}

bool Tables::copyTable(int tableIndex)
{
	int isExists = true;
	if (tables.size() > tableIndex) {
		Table* tableCopy = new Table(tables[tableIndex]);
		tables.push_back(tableCopy);
	}
	else {
		isExists = false;
	}

	return isExists;
}

bool Tables::deleteTable(int tableIndex)
{
	int isExists = true;
	if (tables.size() > tableIndex) {
		delete tables[tableIndex];
		tables.erase(tables.begin() + tableIndex);
	}
	else {
		isExists = false;
	}

	return isExists;
}

void Tables::deleteAllTables()
{
	for (int i = tables.size() - 1; i >= 0; i--) {
		deleteTable(i);
	}
}

bool Tables::printTable(int tableIndex)
{
	bool isExist = true;
	if (tables.size() > tableIndex) {
		tables[tableIndex]->toString();
	}
	else {
		isExist = false;
	}

	return isExist;
}

void Tables::printAll()
{
	if (tables.size() > 0) {
		for (int i = 0; i < tables.size(); i++) {
			tables[i]->toString();
		}
	}
}


