#include <iostream>
#include "header.h"

// Returns a random room between min and max values
int SelectRoom(int min, int max) {
	
	int range = max - min + 1;	// Total number of possible values
	int r = std::rand() % range + min;	// Random number in range (min, max)

	return r;
	
}