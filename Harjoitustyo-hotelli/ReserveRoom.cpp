#include <iostream>
#include <limits>
#include "header.h"
#include "error_messages.h"



void ReserveRoom(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int roomQuantity) {
	int roomNumber;
	bool empty;
	int nights;
	double bill;
	int choice;
	int roomType;
	int confirm;
	std::string customerName;


	do {

		std::cout << "Would you like to pick a room by yourself or have it assigned to you? Pick yourself [1], Have it assigned [0]: ";

		// Validate input
		do {
			validateType(choice, assignRoom_errmsg);

			if (choice != 1 && choice != 0) {
				std::cout << assignRoom_errmsg;
			}

		} while (choice != 1 && choice != 0);

		// Customer picks the room manually
		if (choice == 1) {
			std::cout << "What type of room would you like to reserve? Single [1], Double [0]: ";

			// Validate room type input
			do {
				validateType(roomType, roomType_errmsg);

				if (roomType != 1 && roomType != 0) {
					std::cout << roomType_errmsg;
				}

			} while (roomType != 1 && roomType != 0);

			// Get the limit for the chosen room type
			int limit = RoomRange(roomType, roomQuantity);


			// Ask for specific room number
			if (roomType == 1) {	// Single room
				std::cout << "What room would you like to reserve? (1-" << limit << "): ";
			}
			else if (roomType == 0) {	// Double room
				std::cout << "What room would you like to reserve? (" << limit << "-" << roomQuantity << "): ";
			}


			// Validate room number
			do {
				validateType(roomNumber, room_errmsg(limit));

				if (roomNumber < 1 || roomNumber > limit) {
					std::cout << room_errmsg(limit);
				}

			} while (roomNumber < 1 || roomNumber > limit);

		}

		// Room is assigned
		if (choice == 0) {
			std::cout << "What type of room would you like to reserve? Single [1], Double [0]: ";

			// Validate room type input
			do {
				validateType(roomType, roomType_errmsg);

				if (roomType != 1 && roomType != 0) {
					std::cout << roomType_errmsg;
				}

			} while (roomType != 1 && roomType != 0);


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

			// Randomly select room until an empty one is found
			do {
				roomNumber = SelectRoom(minRoom, maxRoom);	// Pass maximum amount of rooms

			} while (!IsRoomEmpty(rooms, roomNumber));
		}



		// Store reservation data
		empty = IsRoomEmpty(rooms, roomNumber);



		// Reserve room if empty
		if (empty) {

			std::cout << "How many nights would you like to reserve the room for?\n";

			// Validate amount of nights. Must be integer and positive number.
			do {
				validateType(nights, nights_errmsg);

				if (nights < 1) {
					std::cout << nights_errmsg;
				}

			} while (nights < 1); // Max value for amount of nights is not defined


			// Ask customer's name
			do {
				std::cout << "In whose name the reservation is made? (first and last name)\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, customerName);

				std::cout << "Is the following name correct: " << customerName << std::endl << "Yes[1], No[0]: ";

				// Validate input. Must be 1 or 0
				do {
					validateType(confirm, choice_errmsg);

					if (confirm != 1 && confirm != 0) {
						std::cout << choice_errmsg;
					}
				} while (confirm != 1 && confirm != 0);

				// If name is correct break
				if (confirm == 1) {
					break;
				}

			} while (confirm == 0);		// If name is incorrect, ask customer to enter it again



			bill = Bill(rooms, nights, roomNumber);		// Store bill information in variable

			// Print bill
			const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index
			double discount = rooms[index].reservation.discountPercentage;

			if (discount == 0.0) {
				std::cout << "Total cost would be " << bill << " Euros" << " from " << nights << " " << (nights == 1 ? "night" : "nights") << std::endl;
			}
			else {
				std::cout << "You are granted a " << discount * 100 << "% discount from your reservation. The total price from " << 
					nights << " " << (nights == 1 ? "night" : "nights") << " is " << bill << " Euros" << std::endl;
			}

			std::cout << "Confirm reservation? Yes [1], No [0]\n";

			// Validate input. Must be 1 or 0
			do {
				validateType(choice, choice_errmsg);

				if (choice != 1 && choice != 0) {
					std::cout << choice_errmsg;
				}

			} while (choice != 1 && choice != 0);



			if (choice == 1) {
				// Reserve room
				const int index = roomNumber - 1;	// Convert roomNumber to 0 based vector index
				int reservationNumber = GenerateResNum(rooms);
				rooms[index].reservation.reservationNumber = reservationNumber;
				rooms[index].reserved = true;
				rooms[index].reservation.customer = customerName;

				// Create new reservation
				Reservation newReservation;
				newReservation.reservationNumber = reservationNumber;
				newReservation.customer = customerName;
				newReservation.roomNumber = roomNumber;
				newReservation.capacity = rooms[index].capacity;

				// Update reservations vector
				reservations.push_back(newReservation);

				std::cout << "Room " << roomNumber << " is reserved for " << rooms[index].reservation.customer << ".\n";
			}
			else {
				ReserveRoom(rooms, reservations, roomQuantity);		// Start over incase of cancelled reservation 
			}
		}
		else {
			std::cout << "Room " << roomNumber << " is already reserved. Please select another room.\n";
		}


	} while (!empty);	//	Ask customer to select other room if reserved


}