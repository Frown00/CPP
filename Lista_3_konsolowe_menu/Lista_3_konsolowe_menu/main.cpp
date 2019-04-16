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
	

	const char *buildCommand1 = "(Menu glowne, main1; (Dodawanie, add;[Dodaj tablice, create table, create table - tworzy domyslna tablice"
		"create table <nazwa tablicy> <dlugosc> -tworzy tablice o podanej nazwie i dlugosci],"
		"[Kopiuj tablice o podanym indeksie i ja dodaj, copy table, copy table <indeks> -kopiuje tablice o podanym indeksie i dodaje ja na koniec listy],"
		"[Wyswietl tablice o indeksie, print table, print table <indeks> -wyswietla tablice o podanym indeksie],"
		"[Wyswietl wszystkie, print all, print all - wyswietla wszystkie utworzone tablice]), (Zarzadzanie, manage;"
		"[Zmien nazwe podanej tablicy, set name, set name <indeks> <nazwa> -ustawia nazwe dla tablicy o podanym indeksie],"
		"[Zmien dlugosc podanej tablicy, set length, set length <indeks> <dlugosc> -ustawia dlugosc dla tablicy o podanym indeksie],"
		"[Ustaw wartosc dla podanej tablicy o podanym indeksie, set value, set value <indeks> <nr_komorki> <wartosc> -ustawia wartosc dla podanej komorki w tablicy o podanym indeksie],"
		"[Wyswietl tablice o indeksie, print table, print table <indeks> -wyswietla tablice o podanym indeksie],"
		"[Wyswietl wszystkie, print all, print all - wyswietla wszystkie utworzone tablice]), "
		"(Usuwanie, delete;[Usun podana tablice, delete table, delete table <indeks> -usuwa tablice o podanym indeksie],"
		"[Usun wszystkie tablice, delete all, delete all - usuwa wszystkie tablice], [Wyswietl tablice o indeksie, print table, print table <indeks> -wyswietla tablice o podanym indeksie],"
		"[Wyswietl wszystkie, print all, print all - wyswietla wszystkie utworzone tablice]), "
		"[Wyswietl tablice o indeksie, print table, print table <indeks> -wyswietla tablice o podanym indeksie], "
		"[Wyswietl wszystkie, print all, print all - wyswietla wszystkie utworzone tablice])";
	
	const char *buildCommand2 =
		"(Menu, menu;(Add, add;[Uruchom przegladarke, internet, otwiera przegladarke], [Bla bla, bla, bobo])"
		",(Submenu1, submenu1;(Submenu2, submenu2;(Sub, sub;[234, 234, help)), [abc, abc, abcHelp])";

	menu.build(buildCommand1);
	menu.deleteAllItems();
	menu.run();
	//Menu menu;
	//Menu* addingMenu = new Menu("Dodawanie", "add");
	//Menu* manageMenu = new Menu("Zarzadzanie", "manage");
	//Menu* deleteMenu = new Menu("Usuwanie", "delete");
	////Menu* extraMenu = new Menu("Extra", "extra");
	//// GENERAL COMMANDS
	//MenuCommand* printAll = new MenuCommand(
	//	"Wyswietl wszystkie", "print all", 
	//	"print all - wyswietla wszystkie utworzone tablice");
	//MenuCommand* printTable = new MenuCommand(
	//	"Wyswietl tablice o indeksie", "print table", 
	//	"print table <indeks> - wyswietla tablice o podanym indeksie");
	//printAll->assignCommand(new PrintAll());
	//printTable->assignCommand(new PrintTable());
	//
	//
	//// ADDING SUBMENU COMMANDS
	//MenuCommand* createTable = new MenuCommand(
	//	"Dodaj tablice", "create table",
	//	"create table - tworzy domyslna tablice \ncreate table <nazwa tablicy> <dlugosc> - tworzy tablice o podanej nazwie i dlugosci");
	//MenuCommand* copyTable = new MenuCommand(
	//	"Kopiuj tablice o podanym indeksie i ja dodaj", "copy table",
	//	"copy table <indeks> - kopiuje tablice o podanym indeksie i dodaje ja na koniec listy");
	//
	//createTable->assignCommand(new CreateTable());
	//copyTable->assignCommand(new CopyTable());

	//
	//// MANAGE SUBMENU COMMANDS
	//MenuCommand* setName = new MenuCommand(
	//	"Zmien nazwe podanej tablicy", "set name",
	//	"set name <indeks> <nazwa> - ustawia nazwe dla tablicy o podanym indeksie");
	//MenuCommand* setLength = new MenuCommand(
	//	"Zmien dlugosc podanej tablicy", "set length",
	//	"set length <indeks> <dlugosc> - ustawia dlugosc dla tablicy o podanym indeksie");
	//MenuCommand* setValue = new MenuCommand(
	//	"Ustaw wartosc dla podanej tablicy o podanym indeksie", "set value",
	//	"set value <indeks> <nr_komorki> <wartosc> - ustawia wartosc dla podanej komorki w tablicy o podanym indeksie");

	//setName->assignCommand(new SetName());
	//setLength->assignCommand(new SetLength());
	//setValue->assignCommand(new SetValue());

	//// DELETE SUBMENU COMMANDS
	//MenuCommand* deleteTable = new MenuCommand(
	//	"Usun podana tablice", "delete table",
	//	"delete table <indeks> - usuwa tablice o podanym indeksie");
	//MenuCommand* deleteAll = new MenuCommand(
	//	"Usun wszystkie tablice", "delete all",
	//	"delete all - usuwa wszystkie tablice");

	//deleteTable->assignCommand(new DeleteTable());
	//deleteAll->assignCommand(new DeleteAll());

	//menu.addItem(addingMenu);
	//menu.addItem(manageMenu);
	//menu.addItem(deleteMenu);
	//menu.addItem(printTable);
	//menu.addItem(printAll);
	////addingMenu->addItem(extraMenu);
	//addingMenu->addItem(createTable);
	//addingMenu->addItem(copyTable);
	//addingMenu->addItem(printTable);
	//addingMenu->addItem(printAll);

	////extraMenu->addItem(printTable);
	//manageMenu->addItem(setName);
	//manageMenu->addItem(setLength);
	//manageMenu->addItem(setValue);
	//manageMenu->addItem(printTable);
	//manageMenu->addItem(printAll);

	//deleteMenu->addItem(deleteTable);
	//deleteMenu->addItem(deleteAll);
	//deleteMenu->addItem(printTable);
	//deleteMenu->addItem(printAll);
	//menu.run();


	getchar();
	return 0;
}