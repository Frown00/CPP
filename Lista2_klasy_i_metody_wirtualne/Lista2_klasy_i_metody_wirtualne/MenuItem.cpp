#include "MenuItem.h"

void MenuItem::run()
{
	cout << endl << "Menu item" << endl;
}

void MenuItem::run(vector<string> arguments)
{
	cout << endl << "Menu item" << endl;
}

//MenuItem::~MenuItem()
//{
//	cout << "Usunieto: " + s_name << endl;
//}

string MenuItem::getName()
{
	return s_name;
}

string MenuItem::getCommand()
{
	return s_command;
}

string MenuItem::getType()
{
	return type;
}

