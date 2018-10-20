#pragma once
#include "MenuItem.h"
#include <vector>
#include <map>
#include <typeinfo>

class Menu : public MenuItem
{
	vector<MenuItem*> menuItems;
	vector<string> splitString(string cmd, char delimiter);
	bool isCommandExist(string cmd);
	void displayMenu();
public:

	Menu();
	Menu(string name, string cmd);
	~Menu();

	void run();
	void addItem(MenuItem* item);

};

