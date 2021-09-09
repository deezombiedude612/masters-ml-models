#ifndef DRIVER_CPP
#define DRIVER_CPP

#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

#include "GeneticAlgorithm.h"
// #include "LocationNode.h"

#define POP_SIZE 5	// consider evaluation on what size is sensible

using namespace std;

int main(int argc, char **argv) {
	vector<LocationNode> population;

	// generate population of nodes
	population.push_back(LocationNode(0, 0));	 // initial node at (0, 0)
	srand((unsigned)time(0));
	generatePopulation(&population, POP_SIZE);

	// cout << "Population size: " << population.size() << endl;

	// fitness of population - measure latency and time
	vector<double> populationFitness = calculateFitness(population);

	// parent selection

	return 0;
}

#endif
