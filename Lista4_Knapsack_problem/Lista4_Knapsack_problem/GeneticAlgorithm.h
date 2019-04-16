#pragma once
#include "KnapsackProblem.h"
#include "Individual.h"

class GeneticAlgorithm
{
	KnapsackProblem* knapsackProblem;
	int populationSize;
	double crossingProp;
	double mutableProp;
	int iterationNum;
	vector<Individual*> population;
	string generateGenotype();
	void generatePopulation();
	double getRandomNumber();
	void mutation();
	void crossing();

	int drawParentId();
	void deletePopulation();
public:
	GeneticAlgorithm(KnapsackProblem* &knapsackProblem, 
					int populationSize, 
					double crossingProp, 
					double mutableProp,
					int iterationNum);
	~GeneticAlgorithm();
	
	void run();
	void getPopulation();
	Individual* getBestFoundSolution();
	void displayBestSolution();
};

