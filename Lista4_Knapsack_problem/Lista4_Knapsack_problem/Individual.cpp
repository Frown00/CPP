#include "Individual.h"



Individual::Individual()
{
}

Individual::Individual(string genotype)
{
}

Individual::Individual(KnapsackProblem*& knapsackProblem, string genotype)
{
	this->genotype = genotype;
	
	countFitness(*&knapsackProblem);
}


Individual::~Individual()
{
	//cout << "Usunieto" << endl;
}

string Individual::getGenotype()
{
	return genotype;
}

void Individual::setGenotype(string genotype)
{
	this->genotype = genotype;
}

double Individual::getFitness()
{
	return fitness;
}

// cout how good solution is
void Individual::countFitness(KnapsackProblem*& knapsackProblem)
{
	if (knapsackProblem->getGenotypeSize(genotype) <= knapsackProblem->getKnapsackCapacity()) {
		fitness = knapsackProblem->getGenotypeValue(genotype);
	}
	else {
		fitness = 0;
	}
}



// Changes one element of genotype into oposite
// int index - index of the element to change  
void Individual::mutate(int index)
{
	if (index <= genotype.length()) {
		if (genotype[index] == '0')
			genotype[index] = '1';
		else if (genotype[index] == '1')
			genotype[index] = '0';
	}
}

// Crosses two individuals genotypes
// int index - is place where they are crossed
// For example
// ind1 => "0101"
// ind2 => "1010"
// index => 1
// after executing
// ind1 => 0110
// ind2 => 1001
vector<string> Individual::crossing(Individual*& partner, int index)
{
	vector<string> children;
	string genotype1 = "";
	string genotype2 = "";
	genotype1 = this->genotype.substr(0, index) + partner->getGenotype().substr(index, partner->getGenotype().length());
	genotype2 = partner->getGenotype().substr(0, index) + this->genotype.substr(index, this->genotype.length());
	
	children.push_back(genotype1);
	children.push_back(genotype2);

	return children;
}
