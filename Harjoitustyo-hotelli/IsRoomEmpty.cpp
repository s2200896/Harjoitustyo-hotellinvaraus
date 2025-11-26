#include "header.h"

// Returns true, if empty
bool IsRoomEmpty(Room(&rooms)[roomQuantity], int roomNumber) {
	if (rooms[roomNumber - 1].reserved == 1) {	// If reserved return false
		return false;
	}
	else {
		return true;
	}

}