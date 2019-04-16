#pragma once
#include <iostream>
#include "Tables.h"
#include "tools.h"

class Command
{
protected:
	// Commands messages
	const string WRONG_CMD = "! Bledna komenda";
	const string ARG_MUST_BE_NUM = "! Argument musi byc liczba";
	const string FIRST_ARG_MUST_BE_NUM = "! Pierwszy argument musi byc liczba";
	const string SECOND_ARG_MUST_BE_NUM = "! Drugi argument musi byc liczba";
	const string THIRD_ARG_MUST_BE_NUM = "! Trzeci argument musi byc liczba";
	const string WRONG_NUM_OF_ARGS = "! Niewlasciwa ilosc argumentow";
	const string CMD_MUST_HAS_ARGS = "! Ta komenda posiada argumenty";
	const string TABLE_DOES_NOT_EXIST = "! Tablica o podanym indeksie nie istnieje";
	const string TABLE_CREATED = "! Stworzono tablice";
	const string NAME_CHANGED = "! Zmieniono nazwe";
	const string LENGTH_CHANGED = "! Zmieniono dlugosc";
	const string VALUE_CHANGED = "! Ustawiono wartosc";
	const string TABLE_DELETED = "! Tablica zostala usunieta";
	const string ALL_TABLES_DELETED = "! Wszystkie tablice zostaly usuniete";

public:

	virtual void runCommand();
	virtual void runCommand(vector<string> arguments);
	virtual ~Command();
};

