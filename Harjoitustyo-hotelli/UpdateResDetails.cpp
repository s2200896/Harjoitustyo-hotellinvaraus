#include <iostream>
#include "header.h"
#include "error_messages.h"

// Returns 1 if customer wants to cancel booking otherwise 0
int UpdateResDetails(std::vector<Room>& rooms, std::vector<Reservation>& reservations, int & roomQuantity, int & roomNumber, std::string & customerName, int & nights, int & roomType) {
	int selection;

	std::cout << "\nWhat would you like to do?" << std::endl;
	std::cout << "1. Change name\n" << "2. Change Room\n" << "3. Change nights\n\n" << "4. Start over\n" << "5. Cancel booking\n" << "6. Continue\n";

	// Validate input. Must be between 1 and 6
	do {
		validateType(selection, common_errmsg);

		if (selection < 1 || selection > 6) {
			std::cout << common_errmsg;
		}

	} while (selection < 1 || selection > 6);

	// Handle selection

	switch (selection) {
	case 1:
		SelectName(customerName);
		break;

	case 2:
		roomNumber = PickRoom(rooms, roomQuantity, roomType);
		break;

	case 3:
		nights = SelectNights();
		break;

	// Start over
	case 4:
		system("cls");
		ReserveRoom(rooms, reservations, roomQuantity);
		break;

	// Cancel booking
	case 5:
		return 1;
	
	// Continue
	case 6:
		return 0;
	}

	return 0;
}