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
 * @brief Returns cartesian distance between nodes
 * 
 * @param node1 
 * @param node2 
 * @return double 
 */
double cartesianDistance(LocationNode node1, LocationNode node2) {
	double cartesianDistance = 0;

	return cartesianDistance;
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
		// cout << "Current node: " << (*ptr1).getX() << ", " << (*ptr1).getY() << endl;

		// for each node, get Cartesian difference between all nodes
		vector<LocationNode>::iterator ptr2 = population.begin();
		for (int iter = 0; iter < (int)population.size(); ++iter) {
			cartesianDifferences[iter] = (*ptr1).getDisplacement((*ptr2).getX(), (*ptr2).getY());
			ptr2 = next(ptr2, 1);
		}

		// for (int iter = 0; iter < (int)population.size(); ++iter) {
		// 	cout << cartesianDifferences[iter] << endl;
		// }

		// then, get the mean of all Cartesian differences
		double sum = 0;
		for (int iter = 0; iter < (int)population.size(); ++iter)
			sum += cartesianDifferences[iter];

		double thisFitness = sum / population.size();
		fitness.push_back(thisFitness);
		cout << "Fitness: " << thisFitness << endl;
	}
	cout << endl;

	return fitness;
}

#endif