#pragma once
#include "MenuItem.h"
#include <vector>
#include <map>

class Menu : public MenuItem
{
	vector<MenuItem*> menuItems;

	vector<string> splitString(string cmd, char delimiter);
public:
	Menu();
	Menu(string name, string cmd);
	~Menu();

	void run();
	void addItem(MenuItem* item);

};

