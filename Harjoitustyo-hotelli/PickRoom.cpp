#include <iostream>
#include "header.h"
#include "error_messages.h"


int PickRoom(std::vector<Room>& rooms, int roomQuantity, int & roomType) {
	int roomNumber;
	int choice;


	std::cout << "\nWhat type of room would you like to reserve? Single [1], Double [2]: ";

	// Validate input
	do {
		validateType(roomType, roomType_errmsg);

		if (roomType != 1 && roomType != 2) {
			std::cout << roomType_errmsg;
		}

	} while (roomType != 1 && roomType != 2);


	std::cout << "\nWould you like to pick a room by yourself [1] or have it assigned to you [0]?\n";

	do {
		validateType(choice, assignRoom_errmsg);

		if (choice != 1 && choice != 0) {
			std::cout << assignRoom_errmsg;
		}

	} while (choice != 1 && choice != 0);


	// Get the start or end range, depending on chosen room type
	int range = RoomRange(roomType, roomQuantity);

	// Determine room number range for selected type
	int minRoom, maxRoom;
	if (roomType == 1) {	// Single room
		minRoom = 1;
		maxRoom = range;
	}
	else {	// Double room
		minRoom = range;
		maxRoom = roomQuantity;
	}


	// Customer picks the room manually
	if (choice == 1) {

		// Ask for new room number if the selected one is reserved
		do {
			// Ask for specific room number
			if (roomType == 1) {	// Single room
				std::cout << "\nWhat room would you like to reserve? (1-" << range << "): ";
			}
			else if (roomType == 2) {	// Double room
				std::cout << "\nWhat room would you like to reserve? (" << range << "-" << roomQuantity << "): ";
			}


			// Validate room number
			do {
				validateType(roomNumber, room_errmsg(minRoom, maxRoom));

				if (roomNumber < minRoom || roomNumber > maxRoom) {
					std::cout << room_errmsg(minRoom, maxRoom);
				}

			} while (roomNumber < minRoom || roomNumber > maxRoom);

			// Room is already reserved
			if (!IsRoomEmpty(rooms, roomNumber)) {
				std::cout << "\nRoom " << roomNumber << " is already reserved. Please select another room.\n";
			}


		} while (!IsRoomEmpty(rooms, roomNumber));


	}

	// Room is assigned
	if (choice == 0) {

		// Randomly select room until an empty one is found
		do {
			roomNumber = SelectRoom(minRoom, maxRoom);	// min and max values as parameter

		} while (!IsRoomEmpty(rooms, roomNumber));
	}

	return roomNumber;
}