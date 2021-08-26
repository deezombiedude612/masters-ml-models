#ifndef DRIVER_CPP
#define DRIVER_CPP

#include <iostream>
#include <vector>

#include "GeneticAlgorithm.h"
// #include "LocationNode.h"

#define POP_SIZE 5

using namespace std;

int main(int argc, char **argv) {
	vector<LocationNode> population;

	// generate population of nodes
	srand((unsigned)time(0));
	generatePopulation(&population, POP_SIZE);

	// cout << "Population size: " << population.size() << endl;

	// fitness of population

	return 0;
}

#endif
