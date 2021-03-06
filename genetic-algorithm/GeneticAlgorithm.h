#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

// #include <cmath>
// #include <iterator>
// #include <vector>

#include "LocationNode.h"

/**
 * @brief Generates population of nodes with indicated size
 * 
 * @param population 
 * @param size 
 */
void generatePopulation(vector<LocationNode>* population, unsigned int size) {
	for (unsigned int i = 0; i < size; ++i) {
		// need fix to ensure that no two nodes have the same coordinates
		(*population).push_back(LocationNode());
	}
}

/**
 * @brief Fitness function: based on latency and time taken
 * 
 * @param population 
 * @return vector<double> 
 */
vector<double> calculateFitness(vector<LocationNode> population) {
	vector<double> fitness;
	vector<LocationNode>::iterator ptr1;

	for (ptr1 = population.begin(); ptr1 < population.end(); ptr1++) {
		double cartesianDifferences[population.size()];	 // relative Cartesian differences
		// std::cout << "Current node: " << (*ptr1).getX() << ", " << (*ptr1).getY() << endl;

		// for each node, get Cartesian difference between all nodes
		vector<LocationNode>::iterator ptr2 = population.begin();
		for (int iter = 0; iter < (int)population.size(); ++iter) {
			cartesianDifferences[iter] = (*ptr1).getDisplacement((*ptr2).getX(), (*ptr2).getY());
			ptr2 = next(ptr2, 1);
		}

		// for (int iter = 0; iter < (int)population.size(); ++iter) {
		// 	std::cout << cartesianDifferences[iter] << endl;
		// }

		// then, get the mean of all Cartesian differences
		double sum = 0;
		for (int iter = 0; iter < (int)population.size(); ++iter)
			sum += cartesianDifferences[iter];

		double thisFitness = sum / population.size();
		fitness.push_back(thisFitness);
		// std::cout << "Fitness: " << thisFitness << endl;
	}
	// std::cout << endl;

	return fitness;
}

/**
 * @brief Prepares Roulette wheel depicting fitness ratios for all nodes
 * 
 * @param populationFitness 
 * @return vector<double> 
 */
vector<double> calculateFitnessRatio(vector<double> populationFitness) {
	vector<double> roulette;

	// obtain total fitness first
	double totalFitness = 0;
	for (vector<double>::iterator ptr = populationFitness.begin(); ptr < populationFitness.end(); ptr++)
		totalFitness += (*ptr);

	std::cout << "Total Fitness: " << totalFitness << endl;

	for (vector<double>::iterator ptr = populationFitness.begin(); ptr < populationFitness.end(); ptr++) {
		roulette.push_back((*ptr) / totalFitness);
		std::cout << "Fitness Ratio: " << (*ptr) / totalFitness << endl;
	}

	return roulette;
}

#endif