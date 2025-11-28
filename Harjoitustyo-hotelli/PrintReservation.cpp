#include "header.h"

// Prints the latest reservation made to the system
void PrintReservation(std::vector<Reservation> &reservations) {

	// Print error message if no reservations was found
	if (reservations.size() == 0) {
		std::cout << "\nThere isn't currently any active reservations in the system. " << std::endl;
	}
	// Print the latest reservation in the system
	else {
		std::cout << "\nDetails of the latest booking" << std::endl;
		const Reservation& latest = reservations.back();
		std::cout << "\nName: " << latest.customer << std::endl;
		std::cout << "Reservation number: " << latest.reservationNumber << std::endl;
		std::cout << "Room: " << latest.roomNumber << std::endl;
		std::cout << "Room type: " << latest.capacity << " person room" << std::endl;
	}

	
}