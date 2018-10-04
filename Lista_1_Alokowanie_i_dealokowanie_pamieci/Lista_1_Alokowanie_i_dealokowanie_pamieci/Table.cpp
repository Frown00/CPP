#include "Table.h"
#define DEF_NAME "Tablica"
#define DEF_SIZE 10

int* Table::arrayCopy(int* &array, int len)
{
	int* temp = new int[len];

	for (int i = 0; i < len; i++) {
		temp[i] = array[i];
	}
	return temp;
}

Table::Table()
{
	this->name = DEF_NAME;
	this->length = DEF_SIZE;
	this->dynamicArray = new int[this->length];
	for (int i = 0; i < this->length; i++) {
		this->dynamicArray[i] = NULL;
	}
	cout << "bezp: " << this->name << endl;
}

Table::Table(string name, int arrLen)
{
	this->name = name;
	this->length = arrLen;
	this->dynamicArray = new int[this->length];
	for (int i = 0; i < this->length; i++) {
		this->dynamicArray[i] = NULL;
	}
	cout << "param: " << this->name << endl;
}

Table::Table(Table &otherTable)
{
	cout << "kopiuj: " << otherTable.name;
	this->name = otherTable.name + "_copy";
	this->length = otherTable.length;
	this->dynamicArray = new int[this->length];
	this->dynamicArray = arrayCopy(otherTable.dynamicArray, otherTable.length);
}


Table::~Table()
{
	delete this->dynamicArray;
	cout << "usuwam: " << this->name << endl;
}

void Table::setName(string name)
{
	this->name = name;
}

bool Table::setLength(int length)
{
	int* temp = arrayCopy(this->dynamicArray, this->length);
	delete this->dynamicArray;
	this->dynamicArray = arrayCopy(temp, length);
	delete temp;
	for (int i = this->length; i < length; i++) {
		this->dynamicArray[i] = NULL;
	}
	this->length = length;
	return true;
}

int Table::setValue(int cell, int value)
{
	// result = 1 - everything is ok
	// result = 0 - nothing checked
	// result = -1 - wrong cell > length
	// result = -2 - wrong cell < 0
	int result = 0;
	if (this->length > cell && cell >= 0) {
		this->dynamicArray[cell] = value;
		result = 1;
	}
	else if (cell >= 0){
		result = -1;
	}
	else {
		result = -2;
	}

	return result;
}

int* Table::getValue(int cell)
{
	// result = 1 - ok
	//			0 - not checked
	//		   -1 - value not exist
	//		   -2 - wrong cell > length
	//		   -3 - wrong cell < 0
	int result = 0;
	int val = 0;
	if (this->length > cell && cell >= 0) {
		if (this->dynamicArray[cell] != NULL) {
			val = this->dynamicArray[cell];
			result = 1;
		}
		else {
			result = -1;
		}
	}
	else if(cell >= 0) {
		result = -2;
	}
	else {
		result = -3;
	}

	int* rtn = new int[2];
	rtn[0] = val;
	rtn[1] = result;
	return rtn;
}

void Table::toString()
{
	string values = "";

	for (int i = 0; i < this->length; i++) {
		if (this->dynamicArray[i] != NULL) {
			values += to_string(this->dynamicArray[i]);
		}
		else {
			values += "-";
		}
		if(i != this->length-1)
			values += ", ";
	}
	
	cout << endl << this->name + 
		"\n len: " + to_string(this->length) + 
		"\n values: " + values << endl << endl;
}


