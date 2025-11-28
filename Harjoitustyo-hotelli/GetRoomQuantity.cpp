#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"

// Returns a random even number betweem 40 and 300
int GetRoomQuantity() {

	srand(time(0));
	
	int rand = (std::rand() % 131) + 20;	// Generates a number Between 20 and 150	

	return rand * 2;	// Converts it to an even number between 40 and 300

}