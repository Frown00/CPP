#include "GeneticAlgorithm.h"
#include <time.h>
#include <cstdlib>

GeneticAlgorithm::GeneticAlgorithm(KnapsackProblem* &knapsackProblem,
									int populationSize, 
									double crossingProp,
									double mutableProp, 
									int iterationNum)
{
	this->knapsackProblem = *&knapsackProblem;
	this->populationSize = populationSize;
	this->crossingProp = crossingProp;
	this->mutableProp = mutableProp;
	this->iterationNum = iterationNum;

	generatePopulation();
}

GeneticAlgorithm::~GeneticAlgorithm()
{
	deletePopulation();
	delete knapsackProblem;
}

// Returns random genotype
string GeneticAlgorithm::generateGenotype()
{
	// chance in percent (0.5 => 50%)
	const double chanceForZero = 0.5;
	string genotype = "";
	int itemsNum = knapsackProblem->getItemsNumber();
	for (int i = 0; i < itemsNum; i++) {
		double randomNum = getRandomNumber();
		if (randomNum <= chanceForZero) {
			genotype += "0";
		}
		else {
			genotype += "1";
		}
	}
	return genotype;
}

void GeneticAlgorithm::generatePopulation()
{
	for (int i = 0; i < populationSize; i++) {

		string genotype = generateGenotype();
		Individual* individual = new Individual(knapsackProblem, genotype);
		population.push_back(individual);
	}
}

void GeneticAlgorithm::run()
{
	for (int i = 0; i < iterationNum; i++) {

		// Crossing two individual
		crossing();

		// Mutation on every individual
		mutation();
		
	}
}

// 
void GeneticAlgorithm::mutation() {
	double randomNum;
	for (int p = 0; p < populationSize; p++) {
		for (int id = 0; id < knapsackProblem->getItemsNumber(); id++) {
			randomNum = getRandomNumber();
			if (randomNum < mutableProp) {
				population[p]->mutate(id);
			}
		}
		population[p]->countFitness(*&knapsackProblem);
	}
}

// choses two random elements from population and depands on probablity crosses them
// when crosses put new ones (childs) to new population
// when not put random elements from old population
void GeneticAlgorithm::crossing()
{
	vector<Individual*> newPopulation;

	int firstParentId = 0;
	int secondParentId = 0;
	while (newPopulation.size() < population.size()) {
		firstParentId = drawParentId();
		do {
			secondParentId = drawParentId();
		} while (secondParentId == firstParentId);

		double randomNum = getRandomNumber();
		if (randomNum < crossingProp) {
			double randomIndex = rand() % knapsackProblem->getItemsNumber();

			vector<string> genotypes = population[firstParentId]->crossing(population[secondParentId], randomIndex);

			for (int g = 0; g < 2; g++) {
				Individual* child = new Individual(knapsackProblem, genotypes[g]);
				newPopulation.push_back(child);
			}
		}
		else {
			Individual* parent1 = new Individual(knapsackProblem, population[firstParentId]->getGenotype());
			Individual* parent2 = new Individual(knapsackProblem, population[secondParentId]->getGenotype());

			newPopulation.push_back(parent1);
			newPopulation.push_back(parent2);
		}
	}
	deletePopulation();
	for (int k = 0; k < populationSize; k++) {
		population.push_back(newPopulation[k]);
	}
}

// returns id of element from population with bigger fitness
int GeneticAlgorithm::drawParentId()
{
	int parentId = 0;
	int firstRandom = 0;
	int secondRandom = 0;

	firstRandom = rand() % populationSize;
	do {
		secondRandom = rand() % populationSize;
	} while (secondRandom == firstRandom);

	if (population[firstRandom]->getFitness() > population[secondRandom]->getFitness()) {
		parentId = firstRandom;
	}
	else {
		parentId = secondRandom;
	}

	return parentId;
}

void GeneticAlgorithm::deletePopulation()
{
	for (int k = 0; k < population.size(); k++) {
		delete population[k];
	}
	population.clear();
}

void GeneticAlgorithm::getPopulation()
{
	for (int i = 0; i < population.size(); i++) {
		cout << population[i]->getGenotype() << "\t" << population[i]->getFitness()<< endl;
	}
	//cout << generateGenotype();
	//knapsackProblem.showItems();
}

Individual* GeneticAlgorithm::getBestFoundSolution()
{
	int bestSolutionId = 0;
	double bestFitness = population[bestSolutionId]->getFitness();
	for (int i = 1; i < populationSize; i++) {
		if (population[i]->getFitness() > bestFitness) {
			bestSolutionId = i;
			bestFitness = population[i]->getFitness();
		}
	}
	return population[bestSolutionId];
}

void GeneticAlgorithm::displayBestSolution()
{
	Individual* bestSolution = getBestFoundSolution();
	cout << "The best found genotype: " << bestSolution->getGenotype() << endl;
	cout << "Value: " << bestSolution->getFitness() << endl << endl;
	cout << "List of chosen items:" << endl;
	knapsackProblem->showItems(bestSolution->getGenotype());
}


// returns random number between 0.0 and 1.0
double GeneticAlgorithm::getRandomNumber()
{
	double randomNum = rand() / (double)RAND_MAX;

	return randomNum;
}