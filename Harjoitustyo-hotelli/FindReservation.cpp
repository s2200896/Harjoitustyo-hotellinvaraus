#include <iostream>
#include <limits>
#include "header.h"
#include "error_messages.h"

static int findReservationIndex(const std::vector<Reservation>& reservations, int reservationNumber, std::string customerName);

// Find reservation by reservation number or customer name
void FindReservation(std::vector<Reservation>& reservations) {
	int choice;
	std::string customerName = "";
	int reservationNumber = 0;

	std::cout << "\nDo you want to search by reservation number [1] or name [0]? ";

	do {
		validateType(choice, searchCondition_errmsg);

		if (choice != 1 && choice && choice != 0) {
			std::cout << searchCondition_errmsg;
		}
	} while (choice != 1 && choice != 0);

	// Search by reservation number
	if (choice == 1) {

		std::cout << "\nEnter reservation number: ";
		validateType(reservationNumber, reservationNumber_errmsg);

		// -1 if not found, otherwise correct index
		int index = findReservationIndex(reservations, reservationNumber, customerName);

		// Reservation found
		if (index != -1) {
			std::cout << "\nDetails of the booking" << std::endl;
			std::cout << "\nName: " << reservations[index].customer << std::endl;
			std::cout << "Reservation number: " << reservations[index].reservationNumber << std::endl;
			std::cout << "Room: " << reservations[index].roomNumber << std::endl;
			std::cout << "Room type: " << reservations[index].capacity << std::endl;
			
		}
		// Reservation not found
		else {
			std::cout << "\nNo reservation was found." << std::endl;
		}
		
	}

	// Search by name
	if (choice == 0) {

		std::cout << "\nEnter a name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, customerName);

		int index = findReservationIndex(reservations, reservationNumber, customerName);

		// Reservation found
		if (index != -1) {
			std::cout << "\nDetails of the booking" << std::endl;
			std::cout << "\nName: " << reservations[index].customer << std::endl;
			std::cout << "Reservation number: " << reservations[index].reservationNumber << std::endl;
			std::cout << "Room: " << reservations[index].roomNumber << std::endl;
			std::cout << "Room type: " << reservations[index].capacity << std::endl;
		}
		// Reservation not found
		else {
			std::cout << "\nNo reservation was found." << std::endl;
		}


	}

}

// Returns the correct index for reservation or -1 if not found
static int findReservationIndex(const std::vector<Reservation>& reservations, int reservationNumber, std::string customerName) {

	// Search for reservation with given number or name
	for (int i = 0; i < reservations.size(); i++) {
		if (reservations[i].reservationNumber == reservationNumber) {
			return i;
		}
		else if (reservations[i].customer == customerName) {
			return i;
		}

	}
	return -1;
}