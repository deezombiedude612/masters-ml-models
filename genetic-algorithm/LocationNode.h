// #pragma once
#ifndef LOCATIONNODE_H
#define LOCATIONNODE_H

#include <cmath>
#include <ctime>
#include <iostream>

#define NODE_RANGE 25

using namespace std;

class LocationNode {
 private:
	double x;	 // x-coordinate
	double y;	 // y-coordinate

	int getRandomNumber() {
		return (rand() % NODE_RANGE) * pow(-1, ceil(rand() % 2));
	}

 public:
	LocationNode() {
		// set random coordinates
		x = getRandomNumber();
		y = getRandomNumber();

		// cout << "(" << x << ", " << y << ")\n";
	}

	LocationNode(double new_x, double new_y) {
		setX(new_x);
		setY(new_y);
	}

	double getX() { return x; }
	double getY() { return y; }

	void setX(double new_x) { x = new_x; }
	void setY(double new_y) { y = new_y; }

	/**
	 * @brief Get the Displacement between Nodes
	 * 
	 * @param other_x 
	 * @param other_y 
	 * @return double 
	 */
	double getDisplacement(double other_x, double other_y) {
		double diff_x = other_x - x;
		double diff_y = other_y - y;

		return sqrt((diff_x * diff_x) + (diff_y * diff_y));
	}

	/**
	 * @brief Get the Processing Power object
	 * 
	 * @param numberOfTasks 
	 * @return int 
	 */
	int getProcessingPower(int numberOfTasks) {
		return numberOfTasks;
	}

	/**
	 * @brief Compares to see if two nodes are of the same location
	 * 
	 * @param otherNode 
	 * @return true 
	 * @return false 
	 */
	bool operator!=(LocationNode &otherNode) {
		return (getX() == otherNode.getX() && getY() == otherNode.getY());
	}

	/**
	 * @brief Double setter method
	 * 
	 * @param otherNode 
	 */
	void operator=(LocationNode &otherNode) {
		setX(otherNode.getX());
		setY(otherNode.getY());
	}
};

#endif
