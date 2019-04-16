#pragma once
#include "Item.h"
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class KnapsackProblem
{
	// Number of items in knapsack
	int itemsNumber;
	// Possible items to take
	vector<Item*> items;

	double knapsackCapacity;
	void readItems(string itemsFilename);
	void readCapacity(string capacityFilename);
	
	vector<string> splitString(string cmd, char delimiter);
	bool isNumber(const std::string & s);
	vector<int> getItemsIndexes(string genotype);
	void deleteItems();
public:
	static int i;
	KnapsackProblem();
	KnapsackProblem(int a);
	KnapsackProblem(string itemsFilename, string capacityFilename);
	~KnapsackProblem();
	double getKnapsackCapacity();
	int getItemsNumber();
	void showItems(string genotype);
	void showAllItems();
	double getGenotypeValue(string genotype);
	double getGenotypeSize(string genotype);
	
};

