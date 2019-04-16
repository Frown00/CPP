
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "KnapsackProblem.h"
#include "Item.h"
#include "GeneticAlgorithm.h"
#include "Individual.h"

using namespace std;

int main() {
	srand(time(NULL));
	int populationSize = 20;
	double crossingProp = 0.4;
	double mutableProp = 0.2;
	int iterationNum = 1000;
	KnapsackProblem* knapsackProblem = new KnapsackProblem("items.txt", "knapsack_capacity.txt");
	GeneticAlgorithm geneticAlgorithm(knapsackProblem, populationSize, crossingProp, mutableProp, iterationNum);
	geneticAlgorithm.getPopulation();
	//cout << "\nValue : " << knapsackProblem.getGenotypeValue("01101");
	geneticAlgorithm.run();
	cout << endl << endl;
	geneticAlgorithm.getPopulation();
	cout << endl << endl;
	geneticAlgorithm.displayBestSolution();

	getchar();
	return 0;
}