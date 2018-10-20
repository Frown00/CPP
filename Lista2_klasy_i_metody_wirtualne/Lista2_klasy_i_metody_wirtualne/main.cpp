#include <iostream>
#include "Menu.h"
#include "MenuCommand.h"
#include "CreateTable.h"
#include "CopyTable.h"
#include "SetLength.h"
#include "SetName.h"
#include "SetValue.h"
#include "DeleteTable.h"
#include "DeleteAll.h"
#include "PrintAll.h"
#include "PrintTable.h"


int main() {
	Menu menu;
	Menu* addingMenu = new Menu("Dodawanie", "add");
	Menu* manageMenu = new Menu("Zarzadzanie", "manage");
	Menu* deleteMenu = new Menu("Usuwanie", "delete");
	
	// GENERAL COMMANDS
	MenuCommand* printAll = new MenuCommand("Wyswietl wszystkie", "print all");
	MenuCommand* printTable = new MenuCommand("Wyswietl tablice o indeksie", "print table");
	
	printAll->assignCommend(new PrintAll());
	printTable->assignCommend(new PrintTable());
	
	
	// ADDING SUBMENU COMMANDS
	MenuCommand* createTable = new MenuCommand("Dodaj tablice", "create table");
	MenuCommand* copyTable = new MenuCommand("Kopiuj tablice o podanym indeksie i ja dodaj", "copy table");
	
	createTable->assignCommend(new CreateTable());
	copyTable->assignCommend(new CopyTable());

	
	// MANAGE SUBMENU COMMANDS
	MenuCommand* setName = new MenuCommand("Zmien nazwe podanej tablicy", "set name");
	MenuCommand* setLength = new MenuCommand("Zmien dlugosc podanej tablicy", "set length");
	MenuCommand* setValue = new MenuCommand("Ustaw wartosc dla podanej tablicy o podanym indeksie", "set value");

	setName->assignCommend(new SetName());
	setLength->assignCommend(new SetLength());
	setValue->assignCommend(new SetValue());

	// DELETE SUBMENU COMMANDS
	MenuCommand* deleteTable = new MenuCommand("Usun podana tablice", "delete table");
	MenuCommand* deleteAll = new MenuCommand("Usun wszystkie tablice", "delete all");

	deleteTable->assignCommend(new DeleteTable());
	deleteAll->assignCommend(new DeleteAll());


	menu.addItem(addingMenu);
	menu.addItem(manageMenu);
	menu.addItem(deleteMenu);
	menu.addItem(printTable);
	menu.addItem(printAll);

	addingMenu->addItem(createTable);
	addingMenu->addItem(copyTable);
	addingMenu->addItem(printTable);
	addingMenu->addItem(printAll);

	manageMenu->addItem(setName);
	manageMenu->addItem(setLength);
	manageMenu->addItem(setValue);
	manageMenu->addItem(printTable);
	manageMenu->addItem(printAll);

	deleteMenu->addItem(deleteTable);
	deleteMenu->addItem(deleteAll);
	deleteMenu->addItem(printTable);
	deleteMenu->addItem(printAll);

	menu.run();
	getchar();
	return 0;
}