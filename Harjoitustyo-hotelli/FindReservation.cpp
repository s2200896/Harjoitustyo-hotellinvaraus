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
			std::cout << std::endl << std::endl;
			PrintReservationField("Reservation number", std::to_string(reservations[index].reservationNumber));
			std::cout << std::endl;

			PrintReservationField("Room number", std::to_string(reservations[index].roomNumber));
			PrintReservationField("Room type", std::to_string(reservations[index].capacity) + " person room");
			std::cout << std::endl;

			PrintReservationField("Customer name", reservations[index].customer);
			PrintReservationField("Nights staying", std::to_string(reservations[index].duration));
			std::cout << std::endl;

			PrintReservationField("Discount percentage", std::to_string((int)(reservations[index].discountPercentage * 100)) + "%");
			PrintReservationField("Invoice", std::to_string((int)reservations[index].bill) + " euros");
			std::cout << std::endl;
			
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
			std::cout << std::endl << std::endl;
			PrintReservationField("Reservation number", std::to_string(reservations[index].reservationNumber));
			std::cout << std::endl;

			PrintReservationField("Room number", std::to_string(reservations[index].roomNumber));
			PrintReservationField("Room type", std::to_string(reservations[index].capacity) + " person room");
			std::cout << std::endl;

			PrintReservationField("Customer name", reservations[index].customer);
			PrintReservationField("Nights staying", std::to_string(reservations[index].duration));
			std::cout << std::endl;

			PrintReservationField("Discount percentage", std::to_string((int)(reservations[index].discountPercentage * 100)) + "%");
			PrintReservationField("Invoice", std::to_string((int)reservations[index].bill) + " euros");
			std::cout << std::endl;
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