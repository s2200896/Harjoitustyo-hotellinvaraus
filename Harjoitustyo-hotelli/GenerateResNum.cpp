#include "header.h"
#include <cstdlib>

// Generates reservation number between 10000 and 99999
int GenerateResNum(std::vector<Room>& rooms) {
	int resNum;

	while (true) {
		resNum = 10000 + rand() % 90000;

		bool found = false;
		// Check all rooms to see if the generated reservation number is already in use
		for (int i = 0; i < rooms.size(); i++) {
			if (resNum == rooms[i].reservation.reservationNumber) {
				found = true;
				break;
			}
		}
		if (!found) {
			return resNum;
		}
	}
}