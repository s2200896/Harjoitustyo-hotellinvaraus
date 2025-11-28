#include "header.h"

// Returns true, if empty
bool IsRoomEmpty(std::vector<Room>& rooms, int roomNumber) {
	const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index
	if (rooms[index].reserved == 1) {	// If reserved return false
		return false;
	}
	else {
		return true;
	}

}