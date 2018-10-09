#include <iostream>
#include "Menu.h"
#include "Table.h"
#include <vector>

using namespace std;

int main() {

	Menu menu;
	Tables* tables = new Tables();

	menu.start(tables);
	
	getchar();
	return 0;
}