#include <iostream>
#include "header.h"

// Returns either the end range to single room
// or start range for double room
int RoomRange(int choice, int roomQuantity) {
	int singleMax = roomQuantity / 2;	
	int doubleMin = singleMax + 1;	

	if (choice == 1) {
		return singleMax;	// For single
	}
	else if (choice == 0) {
		return doubleMin;	// For double
	}
}