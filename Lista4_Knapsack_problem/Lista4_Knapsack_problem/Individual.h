#pragma once
#include <string>
#include "KnapsackProblem.h"

using namespace std;

class Individual
{
	string genotype;
	double fitness;

public:
	Individual();
	Individual(string genotype);
	Individual(KnapsackProblem*& knapsackProblem, string genotype);
	~Individual();
	string getGenotype();
	void setGenotype(string genotype);

	double getFitness();
	void countFitness(KnapsackProblem*& knapsackProblem);
	void mutate(int index);
	vector<string> crossing(Individual*& partner, int index);
};

