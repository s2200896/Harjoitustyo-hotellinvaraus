#include <iostream>
#include <limits>
#include "header.h"
#include "error_messages.h"



void ReserveRoom(Room& hotel) {
	int roomNumber;
	bool empty;
	int nights;
	double bill;
	int choice;
	int confirm;
	Reservation reservation;


	do {

		std::cout << "What room would you like to reserve? (1-10):\n";

		// Validate room number. Must be integer, more or equal to 1 and less or equal to hotel.quantity (total amount of rooms)
		do {
			validateType(roomNumber, room_errmsg);

			if (roomNumber < 1 || roomNumber > hotel.quantity) {
				std::cout << room_errmsg;
			}

		} while (roomNumber < 1 || roomNumber > hotel.quantity);



		// Store information about the reservation to variable
		empty = IsRoomEmpty(hotel, roomNumber);



		// Reserve room if empty
		if (empty) {
			// Add functionality to store the information about reservation

			std::cout << "How many nights would you like to reserve the room for?\n";

			// Validate amount of nights. Must be integer and positive number.
			do {
				validateType(nights, nights_errmsg);

				if (nights < 1) {
					std::cout << nights_errmsg;
				}

			} while (nights < 1); // Max value for amount of nights is not defined


			// Ask customer's name
			// TODO: Link customer to the room being reserved
			do {
				std::cout << "In whose name the reservation is made? (first and last name)\n";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::getline(std::cin, reservation.customerName);

				std::cout << "Is the following name correct: " << reservation.customerName << std::endl << "Yes[1], No[0]: ";

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



			bill = Bill(hotel, nights);		// Store bill information in variable

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
				std::cout << "Room " << roomNumber << " reserved.\n";
				hotel.roomStatus[roomNumber - 1] = 1; // Reserve room

			}
			else {
				ReserveRoom(hotel);		// Start over incase of cancelled reservation 
			}
		}
		else {
			std::cout << "Room " << roomNumber << " is already reserved. Please select another room.\n";
		}

	} while (!empty);	//	Ask customer to select other room if reserved


}