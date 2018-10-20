#include "Menu.h"
#define BACK "back"
#define CLEAR "clear"
#define MENU "menu"
#define TYPE "Menu"

Menu::Menu()
{
	s_name = "Menu Glowne";
	s_command = "";
	type = TYPE;
}

Menu::Menu(string name, string cmd)
{
	s_name = name;
	s_command = cmd;
	type = TYPE;
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
	
	cout << endl << s_name << endl << endl;
	
	for (int i = 0; i < menuItems.size(); i++) {
		cout << i + 1;
		cout << ". " + menuItems[i]->getName();
		cout << " (" + menuItems[i]->getCommand() + ")" << endl;
		actions.insert(pair<string, MenuItem*>(menuItems[i]->getCommand(), menuItems[i]));
	}
	cout << ".. Cofnij" << " (back)" << endl;

	// Writing command
	bool running = true;
	vector<string> splittedCommand;
	string command = "";

	static bool isBack = false;
	while (running) {
		if (isBack) {
			displayMenu();
			isBack = false;
		}
		
		cout << endl << "> ";
		getline(cin, command);
		splittedCommand = splitString(command, ' ');

		string cmd;
		vector<string> args;
		int cmdSize = splittedCommand.size();	// Number of words in command
		if (cmdSize == 1) {
			cmd = splittedCommand[0];
		}
		else if(cmdSize >= 2) {
			cmd = splittedCommand[0] + " " + splittedCommand[1];

			for (int i = 2; i < splittedCommand.size(); i++) {
				args.push_back(splittedCommand[i]);
			}
		}
		
		//std::map<string, MenuItem>::iterator it;
		if (cmd == BACK) {
			running = false;
			isBack = true;
		}
		else if (cmd == CLEAR) {
			system("cls");
		}
		else if (cmd == MENU) {
			displayMenu();
		}
		else if (actions.find(cmd) != actions.end()) {
			MenuItem* item = actions.find(cmd)->second;
			if (item->getType() == TYPE) {
				item->run();
			}
			else {
				if (args.size() > 0) {
					item->run(args);
				}
				else {
					item->run();
				}
			}
		}
		else {
			cout << endl << "! Komenda nie istnieje" << endl;
		}
	}
}

void Menu::addItem(MenuItem* item)
{
	if(isCommandExist(item->getCommand())) {
		cout << "Nie dodano komendy" << endl;
		cout << "Komenda '" << item->getCommand() << "'" << " istnieje" << endl;;
	}
	else {
		menuItems.push_back(item);
	}
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

bool Menu::isCommandExist(string cmd)
{
	bool isExist = false;

	for (int i = 0; i < menuItems.size(); i++) {
		if (cmd == menuItems[i]->getCommand()) {
			isExist = true;
			break;
		} 
	}
	return isExist;
}

void Menu::displayMenu()
{
	cout << endl << s_name << endl << endl;
	for (int i = 0; i < menuItems.size(); i++) {
		cout << i + 1;
		cout << ". " + menuItems[i]->getName();
		cout << " (" + menuItems[i]->getCommand() + ")" << endl;
	}
	cout << ".. Cofnij" << " (back)" << endl;
}

