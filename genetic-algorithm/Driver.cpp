#ifndef DRIVER_CPP
#define DRIVER_CPP

#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

#include "GeneticAlgorithm.h"
// #include "LocationNode.h"

// consider evaluation on what size is sensible
#define POP_SIZE 5	// population size (minus origin point)

using namespace std;

int main(int argc, char **argv) {
	vector<LocationNode> population;

	// generate population of nodes
	population.push_back(LocationNode(0, 0));	 // initial node at (0, 0)
	srand((unsigned)time(0));
	generatePopulation(&population, POP_SIZE);

	// cout << "Population size: " << population.size() << endl;

	// fitness of population - measure latency and time (by distance)
	vector<double> populationFitness = calculateFitness(population);

	// fitness ratio in a Roulette wheel form
	vector<double> roulette = calculateFitnessRatio(populationFitness);

	// parent selection by selecting from Roulette wheel
	int numberOfParentPairs = floor((POP_SIZE + 1) / 2);
	// cout << "Generating " << numberOfParentPairs << " parent pairs..\n";

	// vector<LocationNode[]> parentPairs;
	vector<vector<LocationNode>> parentPairs;

	for (int iter = 0; iter < numberOfParentPairs; ++iter) {
		LocationNode parents[2];
		double roulette1, roulette2;

		// Parent #1
		roulette1 = (double)rand() / RAND_MAX;
		vector<LocationNode>::iterator parentPtr = population.begin();
		double cumulativeFitnessRatio = 0;
		for (vector<double>::iterator ptr = roulette.begin(); ptr < roulette.end(); ptr++) {
			if (roulette1 < cumulativeFitnessRatio) {
				// parent1 = (*parentPtr);
				parents[0] = (*parentPtr);
				break;
			}
			cumulativeFitnessRatio += (*ptr);
			parentPtr = next(parentPtr, 1);
		}

		// Parent #2 (assume no asexual reproduction, i.e., no node can be picked twice as parent)
		do {
			roulette2 = (double)rand() / RAND_MAX;
			parentPtr = population.begin();
			cumulativeFitnessRatio = 0;

			for (vector<double>::iterator ptr = roulette.begin(); ptr < roulette.end(); ptr++) {
				if (roulette2 < cumulativeFitnessRatio) {
					// parent2 = (*parentPtr);
					parents[1] = (*parentPtr);
					break;
				}
				cumulativeFitnessRatio += (*ptr);
				parentPtr = next(parentPtr, 1);
			}
		} while (parents[0] != parents[1]);

		std::cout << "Roulette 1: " << roulette1 << " (" << parents[0].getX() << ", " << parents[0].getY() << ")\n";
		std::cout << "Roulette 2: " << roulette2 << " (" << parents[1].getX() << ", " << parents[1].getY() << ")\n";

		// parentPairs.push_back(parents);
		vector<LocationNode> pair;
		for (int iter2 = 0; iter2 < 2; ++iter2) pair.push_back(parents[iter2]);
		parentPairs.push_back(pair);
	}

	// perform crossover

	return 0;
}

#endif
