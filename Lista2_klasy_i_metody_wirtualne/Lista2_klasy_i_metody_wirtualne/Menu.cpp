#include "Menu.h"
#define BACK "back"


Menu::Menu()
{
	s_name = "Menu Glowne";
	s_command = "main_menu";
}

Menu::Menu(string name, string cmd)
{
	s_name = name;
	s_command = cmd;
}


Menu::~Menu()
{
	cout << "Menu " << s_name;
}

void Menu::run()
{
	//menuItems[0]->run();
	// Displaying possible options
	map<string, MenuItem*> actions;
	vector<string> commands;
	
	cout << s_name << endl << endl;
	
	for (int i = 0; i < menuItems.size(); i++) {
		cout << i + 1;
		cout << ". " + menuItems[i]->getName();
		cout << " (" + menuItems[i]->getCommand() + ")" << endl;
		commands.push_back(menuItems[i]->getCommand());
		actions.insert(pair<string, MenuItem*>(menuItems[i]->getCommand(), menuItems[i]));
	}

	// Writing command
	bool running = true;
	vector<string> splittedCommand;
	string command = "";

	static bool isBack = false;
	while (running) {
		if (isBack) {
			cout << s_name << endl << endl;
			for (int i = 0; i < menuItems.size(); i++) {
				cout << i + 1;
				cout << ". " + menuItems[i]->getName();
				cout << " (" + menuItems[i]->getCommand() + ")" << endl;
			}
		}

		cout << endl << "> ";
		getline(cin, command);
		splittedCommand = splitString(command, ' ');

		string cmd = splittedCommand[0];
		vector<string> params;

		//std::map<string, MenuItem>::iterator it;
		if (cmd == BACK) {
			running = false;
			isBack = true;
			system("cls");
		}
		else if (actions.find(cmd) != actions.end()) {
			system("cls");
			actions.find(cmd)->second->run();
		}
		else {
			cout << endl << "! Komenda nie istnieje" << endl;
		}
	}
}

void Menu::addItem(MenuItem* item)
{
	menuItems.push_back(item);
}


///// ADDITIONAL FUNCTIONS /////

vector<string> Menu::splitString(string cmd, char delimiter)
{
	vector<string> splittedString;
	string singlePart = "";
	for (int i = 0; i < cmd.length(); i++) {
		if (cmd[i] != delimiter) {
			singlePart += cmd[i];
		}
		else {
			if (singlePart != "") {
				splittedString.push_back(singlePart);
				singlePart = "";
			}
		}
	}
	if (singlePart != "")
		splittedString.push_back(singlePart);
	return splittedString;
}