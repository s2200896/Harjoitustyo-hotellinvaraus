#include <iostream>
#include <limits>
#include "header.h"
#include "error_messages.h"



void ReserveRoom(Room (&rooms)[roomQuantity]) {
	int roomNumber;
	bool empty;
	int nights;
	double bill;
	int choice;
	int confirm;
	std::string customerName;

	Room room;	// To access structure data

	do {

		std::cout << "What room would you like to reserve? (1-10):\n";

		// Validate room number. Must be integer, more or equal to 1 and less or equal to hotel.quantity (total amount of rooms)
		do {
			validateType(roomNumber, room_errmsg);

			if (roomNumber < 1 || roomNumber > roomQuantity) {
				std::cout << room_errmsg;
			}

		} while (roomNumber < 1 || roomNumber > roomQuantity);



		// Store information about the reservation to variable
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



			bill = Bill(room, nights, roomNumber);		// Store bill information in variable

			std::cout << "Total cost would be " << bill << " Euros" << " from " << nights << " nights\n";	 // Condition for whether to print "night" or "nights"?	

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
				int reservationNumber = GenerateResNum(rooms);
				rooms[roomNumber - 1].reservation.reservationNumber = reservationNumber;
				rooms[roomNumber - 1].reserved = true;
				rooms[roomNumber - 1].reservation.customer = customerName;

				std::cout << "Room " << roomNumber << " is reserved for " << rooms[roomNumber - 1].reservation.customer << ".\n";
			}
			else {
				ReserveRoom(rooms);		// Start over incase of cancelled reservation 
			}
		}
		else {
			std::cout << "Room " << roomNumber << " is already reserved. Please select another room.\n";
		}


	} while (!empty);	//	Ask customer to select other room if reserved


}