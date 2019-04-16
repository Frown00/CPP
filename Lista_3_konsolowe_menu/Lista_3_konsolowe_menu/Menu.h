#pragma once
#include "MenuItem.h"
#include "MenuCommand.h"
#include "Help.h"
#include <vector>
#include <map>
#include <typeinfo>

class Menu : public MenuItem
{
	map<string, MenuItem*> actions;
	vector<MenuItem*> menuItems;
	vector<string> splitString(string cmd, char delimiter);
	void splitCommandAndArgs(vector<string> splittedCommand, string &cmd, vector<string> &args);
	string trim(const string& text);
	bool isCommandExist(string cmd);
	void displayHelpForCommand(string cmd);
	void displayMenu();
	void displayPath(string cmd);
	string buildStringTree();

public:
	Menu();
	Menu(string name, string cmd);
	~Menu();
	static string menuTree;
	void build(string menuTree);
	void mapAllCommands();
	void buildMenu(string& menuTree);
	void deleteAllItems();

	void run();
	
	void addItem(MenuItem* item);
	vector<MenuItem*> getMenuItems();
};

