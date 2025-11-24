#include "header.h"

// Returns 1, if empty
bool IsRoomEmpty(const Room& room, int roomNumber) {
	return room.roomStatus[roomNumber - 1] == 0;

}