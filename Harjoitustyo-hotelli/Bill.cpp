#include "header.h"

// Returns the bill from the hotel room
// Add possible discounts later
double Bill(std::vector<Room>& rooms, int nights, int roomNumber) {
	const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index

	// If single room, set price to 100€/night
	if (rooms[index].capacity == 1) {
		rooms[index].price = 100.0;
	}
	// If double room, set price to 150€/night
	else if(rooms[index].capacity == 2) {
		rooms[index].price = 150.0;
	}

	return rooms[index].price * nights;		// Return bill

}