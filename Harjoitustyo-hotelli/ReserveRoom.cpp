#include <iostream>
#include <limits>
#include "header.h"
#include "error_messages.h"



void ReserveRoom(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int roomQuantity) {
	int choice;
	int roomType;
	std::string customerName;

	// Select room
	int roomNumber = PickRoom(rooms, roomQuantity, roomType);

	// Select nights 
	int nights = SelectNights();

	// Select name
	SelectName(customerName);

	
	do {
		// Print reservation details
		PrintResDetails(roomNumber, roomType, nights, customerName);

		std::cout << "\nAre the reservation details correct? Yes [1], No [0]\n";

		// Validate input. Must be 1 or 0
		do {
			validateType(choice, choice_errmsg);

			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}
		} while (choice != 1 && choice != 0);

		if (choice == 0) {
			UpdateResDetails(rooms, reservations, roomQuantity, roomNumber, customerName, nights, roomType);
		}

	} while (choice == 0);

	double discountPercentage = GetDiscountRate();		// Discount percentage
	double bill = Bill(rooms, nights, roomNumber, discountPercentage);		// Store bill information in variable


	PrintBill(rooms, roomNumber, nights, bill);


	do {

		std::cout << "\nConfirm reservation? Yes [1], No [0]\n";

		// Validate input. Must be 1 or 0
		do {
			validateType(choice, choice_errmsg);

			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}

		} while (choice != 1 && choice != 0);


		// Reserve room
		if (choice == 1) {
			MakeReservation(rooms, reservations, customerName, bill, roomNumber, nights);
		}
		// Change desired values
		else {
			// UpdateResDetails() returns 0
			if (!UpdateResDetails(rooms, reservations, roomQuantity, roomNumber, customerName, nights, roomType)) {
				bill = Bill(rooms, nights, roomNumber, discountPercentage);
				PrintBill(rooms, roomNumber, nights, bill);
			}
			// UpdateResDetails() returns 1; user wants to cancel booking
			else {
				break;
			}

		}

	} while (choice == 0);

}