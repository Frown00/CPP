#include "KnapsackProblem.h"
#define WRONG_GENOTYPE "! Genotype is too long!"

KnapsackProblem::KnapsackProblem()
{
}

KnapsackProblem::KnapsackProblem(string itemsFilename, string capacityFilename)
{
	readItems(itemsFilename);
	readCapacity(capacityFilename);
}

KnapsackProblem::~KnapsackProblem()
{
	deleteItems();
}

double KnapsackProblem::getKnapsackCapacity()
{
	return knapsackCapacity;
}

int KnapsackProblem::getItemsNumber()
{
	return itemsNumber;
}

void KnapsackProblem::showItems(string genotype)
{
	vector<int> indexes = getItemsIndexes(genotype);
	for (int i = 0; i < indexes.size(); i++) {
		cout << items[indexes[i]]->getName() << endl;
	}
}

void KnapsackProblem::showAllItems()
{
	cout << "Name" << "\t\t" << "Size" << "\t" << "Value" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < items.size(); i++) {
		cout << items[i]->getName()<< "\t\t" << items[i]->getSize() << "\t" << items[i]->getValue() << endl;
	}
}

// Return value of all items we take
double KnapsackProblem::getGenotypeValue(string genotype)
{
	vector<int> indexes = getItemsIndexes(genotype);
	double totalValue = 0;
	if (indexes.size() == 0) {
		totalValue = -1;
	}
	else {
		for (int i = 0; i < indexes.size(); i++) {
			totalValue += items[indexes[i]]->getValue();
		}
	}
	return totalValue;
}

double KnapsackProblem::getGenotypeSize(string genotype)
{
	vector<int> indexes = getItemsIndexes(genotype);
	double totalSize = 0;
	if (indexes.size() == 0) {
		totalSize = -1;
	}
	else {
		for (int i = 0; i < indexes.size(); i++) {
			totalSize += items[indexes[i]]->getSize();
		}
	}
	return totalSize;
}

// Items size define how long genotype can be.
// Genotype cant be too long, but it is okay to be too short
// If it is too short then rest of genotype is '0'
// Example of genotype => '01011'
// 1 - means that we take item
// 0 - means we don't take item
// so we take 2,4 and 5 item from our posibilities
vector<int> KnapsackProblem::getItemsIndexes(string genotype) {
	vector<int> indexes;
	if (genotype.length() <= itemsNumber) {
		for (int i = 0; i < genotype.length(); i++) {
			if (genotype[i] == '1') {
				indexes.push_back(i);
			}
			else {
				// nothing
			}
		}
	}
	else {
		cout << WRONG_GENOTYPE << endl;
	}
	
	return indexes;
}

// setting items using data from file
void KnapsackProblem::readItems(string itemsFilename)
{
	// File should have UTF-8 encoding
	ifstream infile(itemsFilename);
	string line;
	vector<string> elements;			// contains splitted line from infile
	int i = 0;
	while (getline(infile, line))
	{
		// get rid of some strange characters from beginning of file
		// probably because of using UTF-8
		if (i == 0) 
			line = line.substr(3, line.length());
		
		elements = splitString(line, ' ');
		string name;
		double size = 0;
		double value = 0;
		int indexEndName = 0;
		bool isEndOfName = false;
		for (int j = 0; j < elements.size(); j++) {
			
			//cout << elements[j] << endl;
			if (isNumber(elements[j])) {
				isEndOfName = true;
				name = name.substr(0, name.length());
			}
			if (!isEndOfName) {
				name += elements[j] + " ";
				indexEndName++;
			}
			else {
				if (j == indexEndName) {
					size = stod(elements[j]);

				}
				else if (j == indexEndName + 1) {
					value = stod(elements[j]);
				}
			}
		}

		items.push_back(new Item(name, size, value));
		i++;
	}
	
	itemsNumber = i;
}

// setting knapsack capacity using value from file
void KnapsackProblem::readCapacity(string capacityFilename)
{
	ifstream infile(capacityFilename);
	string line;
	while (getline(infile, line))
	{
		// get rid of some strange characters from beginning of file
		// probably because of using UTF-8
		line = line.substr(3, line.length());

		if(isNumber(line))
			knapsackCapacity = stod(line);
	}
}

void KnapsackProblem::deleteItems() {
	for (int i = 0; i < items.size(); i++) {
		delete items[i];
	}
	items.clear();
}

// Utilities
vector<string> KnapsackProblem::splitString(string cmd, char delimiter)
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

// Check if string is number
bool KnapsackProblem::isNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	
	while (it != s.end() && isdigit(*it) || it !=s.end() && *it == '.') ++it;
	return !s.empty() && it == s.end();
}