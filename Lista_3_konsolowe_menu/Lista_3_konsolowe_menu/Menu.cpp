#include "Menu.h"
#define BACK "back"
#define CLEAR "clear"
#define MENU "menu"
#define HELP "help"
#define SEARCH "search"
#define TYPE_MAIN_MENU "Main menu"
#define TYPE_MENU "Menu"
#define TYPE_COMMAND "Command"
#define COMMAND_DOES_NOT_EXIST "! Brak komendy"


string Menu::menuTree = "";

Menu::Menu()
{

	s_name = "Menu Glowne";
	s_command = "main";
	type = TYPE_MAIN_MENU;
	//menuTree = "abc";
//	menuTree = "(" + s_name + ", " + s_command + ")";
	/*for (int i = 0; i < menuItems.size(); i++) {
		actions.insert(pair<string, MenuItem*>(menuItems[i]->getCommand(), menuItems[i]));
	}*/

}

Menu::Menu(string name, string cmd)
{
	s_name = name;
	s_command = cmd;
	type = TYPE_MENU;
}


Menu::~Menu()
{
	//cout << "Menu " << s_name;
	for (int i = 0; i < menuItems.size(); i++) {
		delete menuItems[i];
	}
	menuItems.clear();
}




void Menu::run()
{
	//menuItems[0]->run();
	// Displaying possible options
	displayMenu();
	if (type == TYPE_MAIN_MENU) {
		menuTree = "(" + this->s_name +"," + this->s_command + ";";
		menuTree += buildStringTree() + " )";
		cout << menuTree << endl;

		//const std::string Menu::menuTree = tree;
	}
	else {
		// do nothing
	}

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
		splitCommandAndArgs(splittedCommand, cmd, args);
		
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
		else if (cmd == HELP) {
			if(args.size() == 1) 
				displayHelpForCommand(args[0]);
			else {
				cout << "\n ! Komenda help wymaga argumentu" << endl;
			}
		}
		else if (cmd == SEARCH) {
			//cout << menuTree;
			if (args.size() == 1) {
				displayPath(args[0]);
			}
			else {
				cout << "\n ! Komenda search wymaga argumentu" << endl;
			}
		}
		else if (actions.find(cmd) != actions.end()) {		// If writing command exist in specific menu
			MenuItem* item = actions.find(cmd)->second;		// Take command or menu and run
			if (item->getType() == TYPE_MENU) {
				item->run();
			}
			else if(item->getType() == TYPE_COMMAND) {
				args.size() > 0 ? item->run(args) : item->run();
			}
		}
		else {
			cout << endl << COMMAND_DOES_NOT_EXIST << endl;
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
		/*if (item->getType() == TYPE_MENU) {
			menuTree += "(" + item->getName() + ", " + item->getCommand() + ")";
			if (menuTree.length() > 0) {
				menuTree[menuTree.length() - 1] = ';';
			}
		}
		else if (item->getType() == TYPE_COMMAND) {
			MenuCommand* menuCommand = (MenuCommand*)item;
			menuTree += "[" + menuCommand->getName() + ", " + menuCommand->getCommand() + "],";
		}*/
		menuItems.push_back(item);
		actions.insert(pair<string, MenuItem*>(item->getCommand(), item));
	}
}

vector<MenuItem*> Menu::getMenuItems()
{
	return menuItems;
}

///// ADDITIONAL FUNCTIONS /////

// Need for divide command and arguments
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

void Menu::splitCommandAndArgs(vector<string> splittedCommand, string &cmd, vector<string> &args)
{
	int cmdSize = splittedCommand.size();	// Number of words in command
	if (cmdSize == 1) {
		cmd = splittedCommand[0];
	}
	else if (cmdSize >= 2) {
		if (splittedCommand[0] == HELP || splittedCommand[0] == SEARCH) {
			cmd = splittedCommand[0];
			if (splittedCommand.size() == 2) {
				args.push_back(splittedCommand[1]);
			}
			else if (splittedCommand.size() == 3)
				args.push_back(splittedCommand[1] + " " + splittedCommand[2]);
		}
		else {
			cmd = splittedCommand[0] + " " + splittedCommand[1];
			for (int i = 2; i < splittedCommand.size(); i++) {
				args.push_back(splittedCommand[i]);
			}
		}
	}
	
}

string Menu::trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

// Searching through all commands in specific menu to find out if have given command exist
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

void Menu::displayHelpForCommand(string cmd) {
	//Help helpCmd = new Help();
	string command = cmd;

	if (actions.find(command) != actions.end()) {
		MenuItem* item = actions.find(command)->second;
		if (item->getType() == TYPE_COMMAND) {
			MenuCommand* menuCommand = (MenuCommand*)item;
			cout << menuCommand->getHelp();
		}
		else {
			cout << COMMAND_DOES_NOT_EXIST;
		}
	}
	else {
		cout << COMMAND_DOES_NOT_EXIST;
	}
}

// Displaying current menu
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

void Menu::displayPath(string cmd)
{
	string tree = this->menuTree;
	string path = "";
	for (int i = 0; i < tree.length(); i++) {
		if (tree[i] == '(') {
			string temp;
			for (int j = i+1; tree[j] != ';'; j++) {
				temp += tree[j];
			}
			vector<string> splitted = splitString(temp, ',');
			path += trim(splitted[1]) + "->";
			if (trim(splitted[1]) == trim(cmd)) {
				path += "\t komenda przejsca do podmenu";
				break;
			}
		}
		if (tree[i] == '[') {
			string command;
			for (int j = i+1; tree[j] != ']'; j++) {
				command += tree[j];
			}
			vector<string> splitted = splitString(command, ',');
			if (trim(splitted[1]) == trim(cmd)) {
				path += trim(cmd);
				break;
			}
			
		}
		if (i == tree.length()-1) {
			path = "! Nie ma takiej komendy";
		}
	}
	cout << path << endl;
}

void Menu::deleteAllItems() {
	for (int i = 0; i < menuItems.size(); i++) {
		delete menuItems[i];
	}
	menuItems.clear();
}

void Menu::build(string menuTree) {
	deleteAllItems();

	string temp;
	if (menuTree.length() > 0) {
		if (menuTree[0] == '(') {
			for (int i = 1; menuTree[i] != ';'; i++) {
					temp += menuTree[i];
			}
			vector<string> menuProp = splitString(temp, ',');
			if (menuProp.size() == 2) {
				this->s_name = menuProp[0];
				this->s_command = menuProp[1];
				string cuttedMenuTree = menuTree.substr(temp.length()+2);
				buildMenu(cuttedMenuTree);
				mapAllCommands();
			}
		}
	}
}

void Menu::mapAllCommands() {
	for (int i = 0; i < this->menuItems.size(); i++) {
		actions.insert(pair<string, MenuItem*>(menuItems[i]->getCommand(), menuItems[i]));
		if (menuItems[i]->getType() == TYPE_MENU) {
			Menu* submenu = (Menu*)menuItems[i];
			submenu->mapAllCommands();
		}
	}
}

void Menu::buildMenu(string& menuTree)
{
	
	menuTree = trim(menuTree);
	
	if (menuTree[0] == '(') {
		string temp;
		for (int i = 1; menuTree[i] != ';'; i++) {
			temp += menuTree[i];
		}
		vector<string> menuProp = splitString(temp, ',');
		if (menuProp.size() == 2) {
			Menu* menu = new Menu(trim(menuProp[0]), trim(menuProp[1]));
			this->menuItems.push_back(menu);
			menuTree = menuTree.substr(temp.length() + 2);
			menu->buildMenu(menuTree);

			menuTree = menuTree.substr(1);

		}
	}

	if (menuTree[0] == '[') {
		string temp;
		for (int i = 1; menuTree[i] != ']'; i++) {
			temp += menuTree[i];
		}
		vector<string> menuProp = splitString(temp, ',');
		if (menuProp.size() == 3) {
			MenuCommand* menuCommand = new MenuCommand(trim(menuProp[0]), trim(menuProp[1]), trim(menuProp[2]));
			this->menuItems.push_back(menuCommand);
			
			menuTree = menuTree.substr(temp.length()+2);
			
			if (menuTree[0] == ',') {
				menuTree = menuTree.substr(1);
				this->buildMenu(menuTree);
			}
			else if (menuTree[0] == ')') {
				// do nothing
			}
		}

		
	}
	if (menuTree[0] == ',') {
		menuTree = menuTree.substr(1);
		this->buildMenu(menuTree);
	}
	
	if (menuTree[0] == ')') {
		// do nothing
		
	}
	
}

string Menu::buildStringTree()
{
	string items = "";

	for (int i = 0; i < menuItems.size(); i++) {
		//cout << "( Item " + menuItems[i]->getType() + ": " + menuItems[i]->getName() + " " + menuItems[i]->getCommand() << endl;
		

		Menu* submenu = ((Menu*)menuItems[i]);
		if (menuItems[i]->getType() == TYPE_MENU) {
			items += "(";
			items += menuItems[i]->getName() + ", " + menuItems[i]->getCommand() + ";";
			items += submenu->buildStringTree();
			items += ")";
		}
		else if(menuItems[i]->getType() == TYPE_COMMAND) {
			items += "[";
			items += menuItems[i]->getName() + ", " + menuItems[i]->getCommand() + ", " + ((MenuCommand*) menuItems[i])->getHelp();
			items += "]";
		}

		if (i != menuItems.size()-1) {
			items += ",";
		}
	}

	
	return items;
}


