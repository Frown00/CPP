#include "Menu.h"


// LOCAL CONSTANTS

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
	if(singlePart != "")
		splittedString.push_back(singlePart);
	return splittedString;
}


bool Menu::isNumber(string num)
{
	bool isNum = true;
	for (int i = 0; i < num.length(); i++) {
		if (!isdigit(num[i])) {
			isNum = false;
			i = num.length();
		}
	}
	return isNum;
}

Menu::Menu()
{
	cout << "LISTA 1 - ALOKOWANIE I DEALOKOWANIE PAMIECI" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Wpisz 'help' aby wyswietlic wszystkie dostepne komendy" << endl << endl;
	start();
}


Menu::~Menu()
{
}

void Menu::start()
{
	bool running = true;
	vector<string> splittedCommand;
	string command = "";

	while(running) {
		cout << "> ";
		getline(cin, command);
		splittedCommand = splitString(command, ' ');
		
		string cmd = "";
		vector<string> params;
		if (splittedCommand.size() > 1) {
			cmd = splittedCommand[0] + " " + splittedCommand[1];

			for (int i = 2; i < splittedCommand.size(); i++) {
				params.push_back(splittedCommand[i]);
			}
			
		}
		else if(splittedCommand.size() > 0){
			cmd = splittedCommand[0];
		}
		else {
			cout << "\n--Niepoprawna komenda--\n" << endl;
		}

		
		switch (decodeCmd(cmd)) {
		case CREATE:
			if (params.size() > 0) {
				if (params.size() == 2) {
					string name = params[0];
					int len = 0;
					if (isNumber(params[1])) {
						len = stoi(params[1]);
						tables->createTable(name, len);
					}
					else {
						cout << "\n--Dlugosc tablicy musi byc liczba--\n";
					}
				}
				else if(params.size() == 1) {
					cout << "\n--Musisz podac dlugosc--\n";
				}
			}
			else {
				tables->createTable();
			}
			break;
		case SET_NAME:
			if (params.size() == 2) {
				if (isNumber(params[0])) {
					bool isSet = tables->setName(stoi(params[0]), params[1]);
					if (isSet) {
						cout << "! Zmieniono nazwe tablicy na " << params[1] << "\n";
					}
					else {
						cout << "--Brak tablicy o podanym indeksie--\n";
					}
				}
				else {
					cout << "--Indeks musi byc liczba--\n";
				}
			}
			else if (params.size() == 1) {
				cout << "--Musisz podac nazwe--\n";
			}
			else if(params.size() == 0) {
				cout << "--Musisz podac parametry--\n";
			}
			else {
				cout << "--Za duza liczba parametrow--\n";
			}
			break;
		case SET_VALUE:
			if (params.size() == 3) {
				if (isNumber(params[0]) && isNumber(params[1]) && isNumber(params[2])) {
					int result = tables->setValue(
						stoi(params[0]),
						stoi(params[1]),
						stoi(params[2]));
					if (result == 1) {
						cout << "! Wpisano wartosc w tablicy o indeksie " + params[0] + " w komorce " + params[1] << endl;
					}
					else if (result == -1) {
						cout << "--Brak takiej komorki - ujemny indeks--\n";
					}
					else if (result == -2) {
						cout << "--Brak takiej komorki - za wysoki indeks--\n";
					}
					else if (result == -3) {
						cout << "--Tablica o podanym indeksie nie istnieje--\n";
					}
				}
				else {
					cout << "--Wszystkie parametry musza byc liczbami--\n";
				}
			}
			break;
		case COPY:
			if (params.size() == 1) {
				if (isNumber(params[0])) {
					bool isExist = tables->copyTable(stoi(params[0]));
					if (!isExist) {
						cout << "--Tablica o podanym indeksie nie istnieje--\n";
					}
					else {
						cout << "! Skopiowane tablice o indeksie " + params[0] + " i dodano\n";
					}
				}
			}
			break;
		case PRINT:
			if (params.size() == 1) {
				if (isNumber(params[0])) {
					bool isExist = tables->printTable(stoi(params[0]));
					if (!isExist) {
						cout << "--Tablica o podanym indeksie nie istnieje--\n";
					}
				}
				else {
					cout << "--Indeks musi byc liczba--\n";
				}
			}
			else {
				cout << "--Niewlasciwa ilosc parametrow--\n";
			}
			break;
		case PRINT_ALL:
			if (params.size() == 0) {
					tables->printAll();
			}
			else {
				cout << "--Niewlasciwa ilosc parametrow--\n";
			}
			break;
		case DELETE:
			if (params.size() == 1) {
				if (isNumber(params[0])) {
					bool isExist = tables->deleteTable(stoi(params[0]));
					if (!isExist) {
						cout << "--Tablica o podanym indeksie nie istnieje--\n";
					}
					else {
						cout << "! Tablica o indeksie " + params[0] + " zostala usunieta\n";
					}
				}
			}
			else {
				cout << "--Niewlasciwa ilosc parametrow--\n";
			}
			break;
		case DELETE_ALL:
			if (params.size() == 0) {
				delete tables;
				cout << "! Usunieto wszystkie tablice\n";
			}
			else {
				cout << "--Niewlasciwa ilosc parametrow--\n";
			}
			break;
		case HELP:
			cout << "\n========== Komendy ==========\n\n";
			cout << "* create table - tworzy domyslna tablice\n";
			cout << "* create table <nazwa> <dlugosc> - tworzy tablice o podanej nazwie i dlugosci\n";
			cout << "* set name <indeks_tablicy> <name> - zmienia nazwe danej tablicy\n";
			cout << "* set value <indeks_tablicy> <indeks_komorki> <wartosc> - wpisuje w danej tablicy wartosc do podanej komorki\n";
			cout << "* copy table <indeks_tablicy> - tworzy kopie danej tablicy i dodaje ja do listy\n";
			cout << "* print table <indeks_tablicy> - wyswietla informacje o danej tablicy\n";
			cout << "* print all - wyswietla informacje o wszystkich tablicach\n";
			cout << "* delete table <indeks_tablic> - usuwa dana tablice\n";
			cout << "* delete all - usuwa wszystkie tablice\n";
			cout << "* clear - czysci konsole\n";
			cout << "* exit - opuszcza program\n\n";
			break;
		case CLEAR:
			system("cls");
			break;
		case EXIT:
			delete tables;
			running = false;
			break;
		default: 
			cout << "--Bledne polecenie--\n";
		}
	}
}
