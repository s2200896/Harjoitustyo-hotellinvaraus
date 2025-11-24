#include <iostream>
#include <limits>
#include <string>
#include "header.h"
#include "error_messages.h"



int main() {
	int input;
	int choice;
	Room hotel;		// Stores reservation data 
	Reservation reservation;



	do {

		std::cout << "How may I help you?" << std::endl;
		std::cout << "1. Reserve Room" << std::endl;

		// Validate menu input
		do {
			validateType(input, common_errmsg);
			if (input != 1) {	// Change condition as the functionality expands
				std::cout << common_errmsg;
			}

		} while (input != 1);



		// Handle selected menu option
		switch (input) {
		case 1: ReserveRoom(hotel);
			break;
			// Add more options later

		}

		// Make sure that there isn't any leftover characters before using cin.get()
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Ask customer if they want to continue
		std::cout << "\nCan I help you with something else? Yes [1], No [0]" << std::endl;

		// Validate input
		do {
			validateType(choice, choice_errmsg);
			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}

		} while (choice != 1 && choice != 0);


		// Greet the customer

	} while (choice == 1);


	return 0;
}


