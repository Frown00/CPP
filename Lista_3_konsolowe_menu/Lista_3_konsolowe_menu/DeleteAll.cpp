#include "DeleteAll.h"



DeleteAll::DeleteAll()
{
}


DeleteAll::~DeleteAll()
{
}

void DeleteAll::runCommand()
{
	tables.deleteAllTables();
	cout << ALL_TABLES_DELETED << endl;
}
