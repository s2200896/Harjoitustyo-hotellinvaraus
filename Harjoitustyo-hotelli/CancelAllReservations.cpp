#include <iostream>
#include "header.h"
#include "error_messages.h"

void CancelAllReservations(std::vector<Room>& rooms, std::vector<Reservation>& reservations) {
	int choice;

	if (!rooms.empty() && !reservations.empty()) {

		std::cout << "\nAre you sure you want to cancel all reservations? Yes [1], No [0]\n";

		do {
			validateType(choice, choice_errmsg);

			if (choice != 1 && choice != 0) {
				std::cout << choice_errmsg;
			}

		} while (choice != 1 && choice != 0);

		if (choice == 1) {
			// Clear rooms vector
			for (auto& room : rooms) {
				room.reservation = Reservation();
				room.reserved = false;
			}

			// Clear reservations vector
			reservations.clear();

			std::cout << "\nAll reservations were canceled.\n";
		}

	}
	else {
		std::cout << "\nThere isn't currently any active reservations in the system.\n";
	}

}