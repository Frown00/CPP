#include <iostream>
#include "Menu.h"
#include "MenuCommand.h"
int main() {
	
	Menu menu;
	Menu* submenu = new Menu("submenu 1", "sub1");
	Menu* submenu2 = new Menu("submenu 2", "sub2");
	MenuCommand* menuCmd = new MenuCommand("Uruchom cos", "cos");
	MenuCommand* menuCmd2 = new MenuCommand("Uruchom cos innego", "cos2");


	//MenuCommand command;
	
	menu.addItem(submenu);
	menu.addItem(menuCmd);
	submenu->addItem(submenu2);
	submenu->addItem(menuCmd2);

	menu.run();
	getchar();
	return 0;
}