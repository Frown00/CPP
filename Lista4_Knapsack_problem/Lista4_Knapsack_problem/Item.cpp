#include "Item.h"
#include <iostream>


Item::Item(const string name, double size, double value)
{
	this->name = name;
	this->value = value;
	this->size = size;
}


Item::~Item()
{
	//cout << "Elo" << endl;
}

string Item::getName()
{
	return name;
}

double Item::getValue()
{
	return value;
}

double Item::getSize()
{
	return size;
}
