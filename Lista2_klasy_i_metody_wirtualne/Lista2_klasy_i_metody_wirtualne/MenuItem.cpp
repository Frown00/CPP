#include "MenuItem.h"

void MenuItem::run()
{
	cout << "Menu item" << endl;
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

