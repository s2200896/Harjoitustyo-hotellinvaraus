#include <iostream>
#include <limits>
#include <string>
#include <ctime>
#include <cstdlib>
#include "header.h"
#include "error_messages.h"



int main() {
	int input;
	int choice;

	srand(time(0));	// For GenerateResNum()


	Room rooms[roomQuantity];	

	// Initialize rooms
	for (int i = 0; i < roomQuantity; i++) {
		rooms[i].roomNumber = i + 1;
	}


	do {

		std::cout << "How may I help you?" << std::endl;
		std::cout << "1. Reserve Room" << std::endl;
		std::cout << "2. Print Reservation" << std::endl;
		std::cout << "3. Find Reservation" << std::endl;
		std::cout << "4. Cancel Reservation" << std::endl;
		std::cout << "5. Print All Reservations" << std::endl;
		std::cout << "6. Exit Program" << std::endl;

		// Validate menu input
		do {
			validateType(input, common_errmsg);
			if (input < 1 || input > 6) {
				std::cout << common_errmsg;
			}

		} while (input < 1 || input > 6);



		// Handle selected menu option
		switch (input) {
		case 1: ReserveRoom(rooms);
			break;
		case 2: PrintReservation();
			break;
		//case 3: FindReservation();
		//	break;
		//case 4: CancelReservation();
		//	break;
		//case 5: PrintAllReservations();
		//	break;
		case 6: return 0;

		}



		// Make sure that there isn't any leftover characters before using cin.get()
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Ask customer if they need help with anything else
		std::cout << "\nCan I help you with something else? Yes [1], No [0]" << std::endl;

		// Validate input
		do {
			validateType(choice, choice_errmsg);
			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}

		} while (choice != 1 && choice != 0);


		// Greet the customer
		std::cout << "Thank you! Wishing you a relaxing and pleasant stay." << std::endl;

	} while (choice == 1);


	return 0;
}


