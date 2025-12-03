#include <iostream>
#include "header.h"

int InitializeRooms(std::vector<Room>& rooms, int roomQuantity) {

	// Resize vector to hold all rooms
	rooms.resize(roomQuantity);

	int half = roomQuantity / 2;	// First half of rooms (1 person rooms)

	// Set the capacity of first half of the rooms to 1 (1 person room)
	for (int i = 0; i < half; i++) {
		rooms[i].roomNumber = i + 1;
		rooms[i].capacity = 1;
	}
	// Set the capacity of second half of the rooms to 2 (2 person room)
	for (int i = half; i < roomQuantity; i++) {
		rooms[i].roomNumber = i + 1;
		rooms[i].capacity = 2;
	}

	return roomQuantity;	// Return total amount of rooms for later use

}