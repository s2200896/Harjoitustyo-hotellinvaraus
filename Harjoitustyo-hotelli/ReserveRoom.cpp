#include <iostream>
#include <limits>
#include "header.h"
#include "error_messages.h"



void ReserveRoom(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int roomQuantity) {
	int choice;
	std::string customerName;

	// Select room
	int roomNumber = PickRoom(rooms, roomQuantity);

	// Select nights 
	int nights = SelectNights();

	// Select name
	SelectName(customerName);


	double discountPercentage = GetDiscountRate();		// Discount percentage
	double bill = Bill(rooms, nights, roomNumber, discountPercentage);		// Store bill information in variable


	PrintBill(rooms, roomNumber, nights, bill);


	do {

		std::cout << "Confirm reservation? Yes [1], No [0]\n";

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
			UpdateResDetails(rooms, reservations, roomQuantity, roomNumber, customerName, nights);
			bill = Bill(rooms, nights, roomNumber, discountPercentage);
		}

	} while (choice == 0);

}