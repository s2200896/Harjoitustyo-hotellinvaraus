#include <iostream>
#include "header.h"
#include "error_messages.h"

void UpdateResDetails(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int & roomQuantity, int & roomNumber, std::string & customerName, int & nights) {
	int selection;

	std::cout << "\nWhich information would you like to change:" << std::endl;
	std::cout << "1. Name\n" << "2. Room\n" << "3. Amount of nights\n" << "4. Start over\n";

	// Validate input. Must be between 1 and 4
	do {
		validateType(selection, common_errmsg);

		if (selection < 1 || selection > 4) {
			std::cout << common_errmsg;
		}

	} while (selection < 1 || selection > 4);

	// Handle selection

	switch (selection) {
	case 1:
		SelectName(customerName);
		break;

	case 2:
		roomNumber = PickRoom(rooms, roomQuantity);
		break;

	case 3:
		nights = SelectNights();
		break;

		// Start over
	case 4:
		system("cls");
		ReserveRoom(rooms, reservations, roomQuantity);
	}
}