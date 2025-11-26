#include "header.h"
#include <cstdlib>
#include <ctime>

// Generates random reservation number between 10000 and 99999
int GenerateResNum() {
	int resNum;
	srand(time(0));

	resNum = 10000 + rand() % 90000;

	// Check if reservation number is already in use

	return resNum;
	
}