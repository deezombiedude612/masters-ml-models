#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <vector>

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

#endif